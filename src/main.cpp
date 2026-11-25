#include <thread>
#include <memory>

#include "another_second_level.hpp"

#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "keyboard.hpp"
#include "mario.hpp"
#include "third_level.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"

#include "app_factory.hpp"

int main(int argc, char* argv[]) {	
	// 1. Установка параметров игры
	using namespace std::chrono_literals;
	
	const int map_height = 30;
	const int map_weight = 140;
	#if defined(QT_GUI)
	QApplication qt_app(argc, argv);
	#endif
	auto frame_delay = std::chrono::milliseconds(0);
	
	biv::Game game;

	biv::AppFactory* app_factory = new biv::AppFactory(&game, map_height, map_weight);
	
	app_factory->control_settings->init();
	app_factory->keyboard->on();
	
	
	
	biv::GameMap* game_map = app_factory->ui_factory->get_game_map(map_height, map_weight);
	biv::GameLevel* first_level = new biv::FirstLevel(app_factory->ui_factory);
    biv::GameLevel* game_level = first_level;
	biv::Mario* mario = app_factory->ui_factory->get_mario();
	
	biv::UserInput user_input;
	do {
		// 2. Получение пользовательского ввода	
		user_input = app_factory->keyboard->get_user_input();
		switch (user_input) {
			case biv::UserInput::MAP_LEFT:
				mario->move_map_left();
				if (!game.check_static_collisions(mario)) {
					game.move_map_left();
				}
				mario->move_map_right();
				break;
			case biv::UserInput::MAP_RIGHT:
				mario->move_map_right();
				if (!game.check_static_collisions(mario)) {
					game.move_map_right();
				}
				mario->move_map_left();
				break;
			case biv::UserInput::MARIO_JUMP:
				mario->jump();
				break;
			case biv::UserInput::EXIT:
				game.finish();
				break;
            case biv::UserInput::NO_INPUT:
                break;
		}
		
		// 3. Обновление внутреннего состояния игры
		game.move_objs_horizontally();
		game.move_objs_with_platforms();
		game.check_horizontally_static_collisions();
		
		game.move_objs_vertically();
		game.check_platforms_collision();
		game.check_mario_collision();
		game.check_vertically_static_collisions();
		
		if (
			game_map->is_below_map(mario->get_top())
			|| !mario->is_active()
		) {
			app_factory->keyboard->off();
			app_factory->keyboard->on();
			game_level->restart();
			mario = app_factory->ui_factory->get_mario();
			std::this_thread::sleep_for(1000ms);
		}
		
		if (game.is_level_end()) {
			if (!game_level->is_final()) {
				game_level = game_level->get_next();
				mario = app_factory->ui_factory->get_mario();
				std::this_thread::sleep_for(1000ms);
				app_factory->keyboard->off();
				app_factory->keyboard->on();
				game.start_level();
			} else {
				game.finish();
			}
		}
		
		// 4. Обновление изображения на экране
		game_map->refresh();
		app_factory->control_settings->set_cursor_start_position();
		game_map->show();
		std::this_thread::sleep_for(frame_delay);
	} while (
		/* 5. Проверка того, не окончена ли игра */ 
		!game.is_finished()
	);
	
	// 6. Завершение
    app_factory->keyboard->off();
    // Первым удаляем уровень/фабрику: QtGameMap уничтожит окно,
    // пока QApplication ещё существует.
    delete first_level;
    delete app_factory;
}
