#include "qt_ui_factory.hpp"

namespace biv {
    QtUIFactory::QtUIFactory(Game* game) : UIFactory(game) {}

    QtUIFactory::~QtUIFactory() {
        clear_data();
        delete game_map;
    }

    template<class T>
    void QtUIFactory::delete_objs(std::vector<T*>& objs) {
        for (T* obj : objs) delete obj;
        objs.clear();
    }

    void QtUIFactory::clear_data() {
        // Сначала убираем указатели из Game и списка отрисовки,
        // только затем удаляем объекты.
        game->remove_objs();
        if (game_map != nullptr) game_map->remove_objs();
        delete mario;
        mario = nullptr;
        delete_objs(boxes);
        delete_objs(full_boxes);
        delete_objs(platforms);
        delete_objs(ships);
        delete_objs(enemies);
        delete_objs(flyable_enemies);
        delete_objs(jumpable_enemies);
        delete_objs(moneys);
    }

    void QtUIFactory::create_box(const Coord& pos, int w, int h) {
        QtBox* obj = new QtBox(pos, w, h);
        boxes.push_back(obj);
        game->add_map_movable(obj);
        game->add_static_obj(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_enemy(const Coord& pos, int w, int h) {
        QtEnemy* obj = new QtEnemy(pos, w, h);
        enemies.push_back(obj);
        game->add_map_movable(obj);
        game->add_movable(obj);
        game->add_collisionable(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_flyable_enemy(const Coord& pos, int w, int h) {
        QtFlyableEnemy* obj = new QtFlyableEnemy(pos, w, h);
        flyable_enemies.push_back(obj);
        game->add_map_movable(obj);
        game->add_movable(obj);
        game->add_collisionable(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_jumpable_enemy(const Coord& pos, int w, int h) {
        QtJumpableEnemy* obj = new QtJumpableEnemy(pos, w, h);
        jumpable_enemies.push_back(obj);
        game->add_map_movable(obj);
        game->add_movable(obj);
        game->add_collisionable(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_full_box(const Coord& pos, int w, int h) {
        QtFullBox* obj = new QtFullBox(pos, w, h, this);
        full_boxes.push_back(obj);
        game->add_collisionable(obj);
        game->add_map_movable(obj);
        game->add_static_obj(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_mario(const Coord& pos, int w, int h) {
        if (mario != nullptr) {
            game->remove_collisionable(mario);
            game->remove_movable(mario);
            game->remove_mario();
            if (game_map != nullptr) game_map->remove_obj(mario);
            delete mario;
        }
        mario = new QtMario(pos, w, h);
        game->add_collisionable(mario);
        game->add_movable(mario);
        game->add_mario(mario);
        game_map->add_obj(mario);
    }

    void QtUIFactory::create_money(const Coord& pos, int w, int h) {
        QtMoney* obj = new QtMoney(pos, w, h);
        moneys.push_back(obj);
        game->add_map_movable(obj);
        game->add_movable(obj);
        game->add_collisionable(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_platform(const Coord& pos, int w, int h) {
        QtPlatform* obj = new QtPlatform(pos, w, h);
        platforms.push_back(obj);
        game->add_map_movable(obj);
        game->add_movable(obj);
        game->add_collisionable(obj);
        game->add_movable_and_collisionable_obj(obj);
        game_map->add_obj(obj);
    }

    void QtUIFactory::create_ship(const Coord& pos, int w, int h) {
        QtShip* obj = new QtShip(pos, w, h);
        ships.push_back(obj);
        game->add_map_movable(obj);
        game->add_static_obj(obj);
        game_map->add_obj(obj);
    }

    GameMap* QtUIFactory::get_game_map(int h, int w) {
        if (game_map == nullptr) game_map = new QtGameMap(h, w);
        return game_map;
    }

    Mario* QtUIFactory::get_mario() { return mario; }
}
