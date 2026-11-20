#include "qt_enemy.hpp"

using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height) 
	: Enemy(top_left, width, height) {}

biv::QtSprite QtEnemy::get_sprite() const noexcept {
	return QtSprite::ENEMY;
}

// Убитого врага не рисуем.
bool QtEnemy::is_visible() const noexcept {
	return is_active();
}
