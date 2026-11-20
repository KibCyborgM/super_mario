#pragma once

#include "console_ui_obj_mov_col_adapter.hpp"
#include "platform.hpp"

namespace biv {
	class ConsolePlatform : public Platform, public ConsoleUIObjectMovColAdapter {
		public:
			ConsolePlatform(const Coord& top_left, const int width, const int height);
			
			char get_brush() const noexcept override;
	};
}