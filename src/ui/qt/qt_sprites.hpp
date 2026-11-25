#pragma once

#include <map>

#include <QPixmap>

#include "qt_sprite.hpp"

namespace biv {
	class QtSprites {
		public:
			static constexpr int CELL_SIZE = 16;

		private:
			std::map<QtSprite, QPixmap> pixmaps;

		public:
			QtSprites();

			const QPixmap& get(const QtSprite sprite) const;

		private:
			void load(const QtSprite sprite, const char* file_name);
	};
}
