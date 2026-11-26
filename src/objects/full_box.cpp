#include <random>

#include "full_box.hpp"

using biv::FullBox;

FullBox::FullBox(
	const Coord& top_left, 
	const int width, const int height,
	UIFactory* ui_factory
) : Box(top_left, width, height), ui_factory(ui_factory) {}

biv::Rect FullBox::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FullBox::get_speed() const noexcept {
	return {0, 0};
}

void FullBox::process_horizontal_static_collision(Rect* obj) noexcept {}

void FullBox::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v < 0) {
		kill();

		std::random_device rd;
    	std::mt19937 gen(rd());
    	std::uniform_int_distribution<int> dist(0, 1);

		if (dist(gen) == 0) {
			ui_factory->create_heal_kit({top_left.x, top_left.y - 3}, 3, 2);
		} else {
			ui_factory->create_damage_box({top_left.x, top_left.y - 3}, 3, 2);
		}
	}
}

void FullBox::process_vertical_static_collision(Rect* obj) noexcept {}

void FullBox::process_vertical_platform_collision(Movable* obj) noexcept {}
