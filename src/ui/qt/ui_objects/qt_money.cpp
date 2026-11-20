#include "qt_money.hpp"

using biv::QtMoney;

QtMoney::QtMoney(const Coord& top_left, const int width, const int height) 
	: Money(top_left, width, height) {}

biv::QtSprite QtMoney::get_sprite() const noexcept {
	return QtSprite::MONEY;
}

// Подобранную монету не рисуем.
bool QtMoney::is_visible() const noexcept {
	return is_active();
}
