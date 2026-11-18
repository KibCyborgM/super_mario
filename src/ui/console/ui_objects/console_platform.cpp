#include "console_platform.hpp"

using biv::ConsolePlatform;

ConsolePlatform::ConsolePlatform(const Coord& top_left, const int width, const int height) 
	:MovableCollisionable(top_left, width, height, 0.0f, 0.2f), Platform(top_left, width, height) {}

char ConsolePlatform::get_brush() const noexcept {
	return '#';
}
