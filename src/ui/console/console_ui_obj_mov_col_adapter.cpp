#include "console_ui_obj_mov_col_adapter.hpp"

using biv::ConsoleUIObjectMovColAdapter;

ConsoleUIObjectMovColAdapter::ConsoleUIObjectMovColAdapter(
	const Coord& top_left, const int width, const int height
) {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
}

