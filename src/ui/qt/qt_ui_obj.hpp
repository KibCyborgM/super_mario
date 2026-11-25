#pragma once

#include "qt_sprite.hpp"

namespace biv {
	class QtUIObject {
		public:
            virtual ~QtUIObject() = default;
			virtual int get_bottom() const noexcept = 0;
			virtual int get_height() const noexcept = 0;
			virtual int get_left() const noexcept = 0;
			virtual int get_right() const noexcept = 0;
			virtual QtSprite get_sprite() const noexcept = 0;
			virtual int get_top() const noexcept = 0;
			virtual bool is_visible() const noexcept = 0;
	};
}
