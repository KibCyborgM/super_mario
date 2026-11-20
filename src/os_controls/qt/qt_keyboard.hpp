/**
	Считывание клавиатуры через Qt.

	Qt сообщает о клавишах событиями (нажата / отпущена), а игровой цикл
	опрашивает клавиатуру сам: keyboard->get_user_input(). Поэтому класс
	запоминает состояние клавиш в фильтре событий, а get_user_input()
	сначала даёт Qt обработать накопившиеся события, а потом отвечает,
	что сейчас нажато. Игровой цикл и контроллер при этом не меняются.
*/

#pragma once

#include <QObject>

#include "keyboard.hpp"

class QEvent;

namespace biv {
	class QtKeyboard : public QObject, public KeyBoard {
		private:
			bool is_on = false;
			
			bool left_pressed = false;
			bool right_pressed = false;
			bool jump_pressed = false;
			// Прыжок, который ещё не был передан игре (одно нажатие - один прыжок).
			bool jump_requested = false;
			bool exit_requested = false;

		public:
			UserInput get_user_input() override;
			void off() override;
			void on() override;

		protected:
			bool eventFilter(QObject* watched, QEvent* event) override;

		private:
			void process_key(const int key, const bool pressed) noexcept;
			void release_keys() noexcept;
	};
}
