#include "qt_damage_box.hpp"

using biv::QtDamageBox;

QtDamageBox::QtDamageBox(const Coord& top_left, const int width, const int height) 
	: DamageBox(top_left, width, height) {}

biv::QtSprite QtDamageBox::get_sprite() const noexcept {
	return QtSprite::DAMAGE_BOX;
}

bool QtDamageBox::is_visible() const noexcept {
	return is_active();
}
