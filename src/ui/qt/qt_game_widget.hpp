#pragma once

#include <QPixmap>
#include <QWidget>

class QPaintEvent;

namespace biv {
	/**
		Окно игры. Само ничего не знает об игре: 
		показывает готовый кадр, который для него нарисовал QtGameMap.
	*/
	class QtGameWidget : public QWidget {
		private:
			const QPixmap* frame;

		public:
			explicit QtGameWidget(const QPixmap* frame);

		protected:
			void paintEvent(QPaintEvent* event) override;
	};
}
