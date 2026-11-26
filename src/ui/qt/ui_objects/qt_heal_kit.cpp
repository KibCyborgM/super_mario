#include "qt_heal_kit.hpp"

using biv::QtHealKit;

QtHealKit::QtHealKit(const Coord& top_left, const int width, const int height) 
	: HealKit(top_left, width, height) {}

biv::QtSprite QtHealKit::get_sprite() const noexcept {
	return QtSprite::HEAL_KIT;
}

bool QtHealKit::is_visible() const noexcept {
	return is_active();
}
