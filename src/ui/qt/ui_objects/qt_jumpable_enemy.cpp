#include "qt_jumpable_enemy.hpp"

using biv::QtJumpableEnemy;

QtJumpableEnemy::QtJumpableEnemy(const Coord& top_left, const int width, const int height) 
	: JumpableEnemy(top_left, width, height) {}

biv::QtSprite QtJumpableEnemy::get_sprite() const noexcept {
	return QtSprite::JUMPABLE_ENEMY;
}

// Убитого врага не рисуем.
bool QtJumpableEnemy::is_visible() const noexcept {
	return is_active();
}
