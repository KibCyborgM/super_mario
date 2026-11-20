#include "qt_box.hpp"

using biv::QtBox;

QtBox::QtBox(const Coord& top_left, const int width, const int height) 
	: Box(top_left, width, height) {}

biv::QtSprite QtBox::get_sprite() const noexcept {
	return QtSprite::BOX;
}
