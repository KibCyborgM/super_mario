#pragma once

#include <QPixmap>
#include <QWidget>

class QPaintEvent;

namespace biv {
	class QtGameWidget : public QWidget {
		private:
			const QPixmap* frame;

		public:
			explicit QtGameWidget(const QPixmap* frame);

		protected:
			void paintEvent(QPaintEvent* event) override;
	};
}
