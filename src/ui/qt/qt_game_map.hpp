#pragma once

#include <vector>

#include <QPixmap>

#include "game_map.hpp"
#include "qt_game_widget.hpp"
#include "qt_sprites.hpp"
#include "qt_ui_obj.hpp"

class QPainter;

namespace biv {
	class QtGameMap : public GameMap {
		private:
			// Сколько столбцов карты помещается в окно. Марио стоит на месте, 
			// а карта едет под ним, поэтому окно может быть уже самой карты.
			static constexpr int MAX_VISIBLE_WIDTH = 80;
			static constexpr int WATER_HEIGHT = 3;

		private:
			QtSprites sprites;
			QPixmap frame;
			QtGameWidget* widget = nullptr;
			
			std::vector<QtUIObject*> objs;
			
		public:
			QtGameMap(const int height, const int width);
			~QtGameMap();
			
			void add_obj(QtUIObject*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject*);
			void remove_objs() override;
			void show() const noexcept override;

		private:
			void draw_obj(QPainter& painter, const QtUIObject* obj) const;
			void draw_tiles(
				QPainter& painter, const QPixmap& sprite,
				const int left, const int top, const int right, const int bottom
			) const;
	};
}
