#pragma once
#include <vector>

#include "qt_box.hpp"
#include "qt_damage_box.hpp"
#include "qt_enemy.hpp"
#include "qt_heal_kit.hpp"
#include "qt_flyable_enemy.hpp"
#include "qt_jumpable_enemy.hpp"
#include "qt_full_box.hpp"
#include "qt_game_map.hpp"
#include "qt_mario.hpp"
#include "qt_platform.hpp"
#include "qt_ship.hpp"
#include "ui_factory.hpp"

namespace biv {
    class QtUIFactory final : public UIFactory {
        private:
            QtGameMap* game_map = nullptr;
            std::vector<QtBox*> boxes;
            std::vector<QtDamageBox*> damage_boxes;
            std::vector<QtFullBox*> full_boxes;
            std::vector<QtHealKit*> heal_kits;
            std::vector<QtPlatform*> platforms;
            std::vector<QtShip*> ships;
            QtMario* mario = nullptr;
            std::vector<QtEnemy*> enemies;
            std::vector<QtFlyableEnemy*> flyable_enemies;
            std::vector<QtJumpableEnemy*> jumpable_enemies;

            template<class T>
            void delete_objs(std::vector<T*>& objs);

        public:
            explicit QtUIFactory(Game* game);
            ~QtUIFactory() override;

            GameMap* get_game_map(int height, int width) override;
            Mario* get_mario() override;

            void clear_data() override;
            void create_box(const Coord&, int width, int height) override;
            void create_damage_box(const Coord&, int width, int height) override;
            void create_enemy(const Coord&, int width, int height) override;
            void create_flyable_enemy(const Coord&, int width, int height) override;
            void create_heal_kit(const Coord&, int width, int height) override;
            void create_jumpable_enemy(const Coord&, int width, int height) override;
            void create_full_box(const Coord&, int width, int height) override;
            void create_mario(const Coord&, int width, int height) override;
            void create_platform(const Coord&, int width, int height) override;
            void create_ship(const Coord&, int width, int height) override;
    };
}
