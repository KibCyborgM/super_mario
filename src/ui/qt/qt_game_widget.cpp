#include "qt_game_widget.hpp"

#include <QPainter>

using biv::QtGameWidget;

QtGameWidget::QtGameWidget(const QPixmap* frame) : frame(frame) {
	setWindowTitle("Super Mario");
	// Размер окна равен размеру кадра: картинка никогда не растягивается.
	setFixedSize(frame->size());
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void QtGameWidget::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, *frame);
}
