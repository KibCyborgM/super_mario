#include "console_heal_kit.hpp"

using biv::ConsoleHealKit;

ConsoleHealKit::ConsoleHealKit(const Coord& top_left, const int width, const int height) 
	: HealKit(top_left, width, height) {}

char ConsoleHealKit::get_brush() const noexcept {
	return '5';
}
