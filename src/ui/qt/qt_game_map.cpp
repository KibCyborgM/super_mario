#include "qt_game_map.hpp"
#include "qt_mario.hpp"

#include <algorithm>

#include <QColor>
#include <QFont>
#include <QFontMetrics>
#include <QString>
#include <QPainter>

using biv::QtGameMap;

namespace {
	const int CELL = biv::QtSprites::CELL_SIZE;
	
	const QColor SKY_COLOR(110, 198, 255);
	
	// Положение облаков в клетках карты: {столбец, строка}.
	const int CLOUDS[][2] = {{6, 3}, {27, 7}, {46, 2}, {66, 6}};
}

QtGameMap::QtGameMap(const int height, const int width) 
	: GameMap(height, width)
	, frame(std::min(width, MAX_VISIBLE_WIDTH) * CELL, height * CELL) {

	clear();
	
	widget = new QtGameWidget(&frame);
	widget->show();
}

QtGameMap::~QtGameMap() {
	delete widget;
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::add_mario(biv::QtMario* mario) {
	mario_obj = mario;
}

void QtGameMap::clear() noexcept {
	QPainter painter(&frame);
	
	// Воздух
	painter.fillRect(frame.rect(), SKY_COLOR);
	
	for (const auto& cloud: CLOUDS) {
		painter.drawPixmap(
			cloud[0] * CELL, cloud[1] * CELL, sprites.get(QtSprite::CLOUD));
	}
	
	// Вода
	draw_tiles(
		painter, sprites.get(QtSprite::WATER), 
		0, (height - WATER_HEIGHT) * CELL, frame.width(), height * CELL
	);
}

void QtGameMap::refresh() noexcept {
	clear();
	
	QPainter painter(&frame);
	for (const QtUIObject* obj: objs) {
		if (obj->is_visible()) {
			draw_obj(painter, obj);
		}
	}
	// Индикатор здоровья рисуется поверх игровых объектов.
	draw_hp(painter);
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	if (obj == mario_obj) {
		mario_obj = nullptr;
	}
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
	objs.clear();
	mario_obj = nullptr;
}

void QtGameMap::show() const noexcept {
	// repaint() перерисовывает окно сразу, не дожидаясь очереди событий Qt.
	widget->repaint();
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
void QtGameMap::draw_hp(QPainter& painter) const {
	if (mario_obj == nullptr) {
		return;
	}

	painter.save();
	QFont font("Arial");
	font.setPixelSize(24);
	font.setBold(true);
	painter.setFont(font);

	const int x = 10;
	const int y = 10 + painter.fontMetrics().ascent();
	const QString label = QStringLiteral("HP:");
	painter.setPen(Qt::black);
	painter.drawText(x, y, label);

	QString hearts;
	for (int i = 0; i < mario_obj->get_hp(); i++) {
		hearts += QChar(0x2665);
	}

	painter.setPen(QColor(220, 30, 40));
	painter.drawText(x + painter.fontMetrics().horizontalAdvance(label) + 8, y, hearts);
	painter.restore();
}

void QtGameMap::draw_obj(QPainter& painter, const QtUIObject* obj) const {
	// Координаты объекта заданы в клетках карты, а рисуем в пикселях.
	const int left = obj->get_left() * CELL;
	const int top = obj->get_top() * CELL;
	const int right = obj->get_right() * CELL;
	const int bottom = obj->get_bottom() * CELL;
	
	// Объект целиком за границами окна.
	if (right <= 0 || left >= frame.width() || bottom <= 0 || top >= frame.height()) {
		return;
	}
	
	draw_tiles(painter, sprites.get(obj->get_sprite()), left, top, right, bottom);
}

/**
	Закрашивает прямоугольник спрайтом, как плиткой.
	
	Спрайт не растягивается и не сжимается. Если объект совпадает со спрайтом 
	по размеру (марио, враг), спрайт рисуется один раз. Если объект больше 
	(корабль, длинная полка), спрайт повторяется, а последняя плитка обрезается 
	по границе объекта.
*/
void QtGameMap::draw_tiles(
	QPainter& painter, const QPixmap& sprite,
	const int left, const int top, const int right, const int bottom
) const {
	for (int y = top; y < bottom; y += sprite.height()) {
		for (int x = left; x < right; x += sprite.width()) {
			const int tile_width = std::min(sprite.width(), right - x);
			const int tile_height = std::min(sprite.height(), bottom - y);
			painter.drawPixmap(x, y, sprite, 0, 0, tile_width, tile_height);
		}
	}
}
