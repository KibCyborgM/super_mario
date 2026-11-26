#include "console_damage_box.hpp"

using biv::ConsoleDamageBox;

ConsoleDamageBox::ConsoleDamageBox(const Coord& top_left, const int width, const int height) 
	: DamageBox(top_left, width, height) {}

char ConsoleDamageBox::get_brush() const noexcept {
	return '2';
}
