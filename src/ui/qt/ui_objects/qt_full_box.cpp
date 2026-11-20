#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left, 
	const int width, const int height,
	UIFactory* ui_factory
) : FullBox(top_left, width, height, ui_factory) {}

biv::QtSprite QtFullBox::get_sprite() const noexcept {
	// Пока из ящика не выбили монету, он рисуется со звездой.
	if (is_active_) {
		return QtSprite::FULL_BOX;
	} else {
		return QtSprite::EMPTY_BOX;
	}
}
