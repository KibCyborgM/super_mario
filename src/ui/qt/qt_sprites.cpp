#include "qt_sprites.hpp"

#include <QString>
#include <QtGlobal>

using biv::QtSprites;

QtSprites::QtSprites() {
	load(QtSprite::BOX, "box.png");
	load(QtSprite::CLOUD, "cloud.png");
	load(QtSprite::EMPTY_BOX, "empty_box.png");
	load(QtSprite::ENEMY, "enemy.png");
	load(QtSprite::FLYABLE_ENEMY, "flyable_enemy.png");
	load(QtSprite::FULL_BOX, "full_box.png");
	load(QtSprite::JUMPABLE_ENEMY, "jumping_enemy.png");
	load(QtSprite::MARIO, "mario.png");
	load(QtSprite::MONEY, "money.png");
	load(QtSprite::PLATFORM, "moving_platform.png");
	load(QtSprite::SHIP, "ship.png");
	load(QtSprite::WATER, "water.png");
}

const QPixmap& QtSprites::get(const QtSprite sprite) const {
	return pixmaps.at(sprite);
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
void QtSprites::load(const QtSprite sprite, const char* file_name) {
	// ":/sprites/..." - путь внутри ресурсов программы (файл sprites.qrc).
	QPixmap pixmap(QString(":/sprites/") + file_name);
	if (pixmap.isNull()) {
		qFatal("Не удалось загрузить спрайт %s", file_name);
	}
	pixmaps[sprite] = pixmap;
}
