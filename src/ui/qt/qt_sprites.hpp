#pragma once

#include <map>

#include <QPixmap>

#include "qt_sprite.hpp"

namespace biv {
	/**
		Хранилище картинок: каждая загружается один раз и рисуется много раз.
		
		Размер картинки фиксированный и задан в пикселях самим файлом:
		одна клетка карты - это QtSprites::CELL_SIZE пикселей.
	*/
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
