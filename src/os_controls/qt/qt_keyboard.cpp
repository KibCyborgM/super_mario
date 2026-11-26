#include "qt_keyboard.hpp"

#include <QCoreApplication>
#include <QEvent>
#include <QKeyEvent>

using biv::QtKeyBoard;
using biv::UserInput;

namespace {
	// Коды тех же клавиш в русской раскладке: Qt сообщает букву, а не кнопку.
	const int KEY_CYRILLIC_F = 0x0424;	// Ф (клавиша A)
	const int KEY_CYRILLIC_V = 0x0412;	// В (клавиша D)
	const int KEY_CYRILLIC_C = 0x0426;	// Ц (клавиша W)
	const int KEY_CYRILLIC_J = 0x0419;	// Й (клавиша Q)

	bool is_left_key(const int key) {
		return key == Qt::Key_A || key == Qt::Key_Left || key == KEY_CYRILLIC_F;
	}

	bool is_right_key(const int key) {
		return key == Qt::Key_D || key == Qt::Key_Right || key == KEY_CYRILLIC_V;
	}

	bool is_jump_key(const int key) {
		return key == Qt::Key_Space || key == Qt::Key_W || key == Qt::Key_Up 
			|| key == KEY_CYRILLIC_C;
	}

	bool is_exit_key(const int key) {
		return key == Qt::Key_Q || key == Qt::Key_Escape || key == KEY_CYRILLIC_J;
	}
}

UserInput QtKeyBoard::get_user_input() {
	// Игровой цикл не отдаёт управление Qt, поэтому события окна
	// (клавиши, перерисовка, закрытие) обрабатываются здесь.
	QCoreApplication::processEvents();

	if (exit_requested) {
		return UserInput::EXIT;
	}
	if (jump_requested) {
		jump_requested = false;
		return UserInput::MARIO_JUMP;
	}
	// Как и в консольных версиях: марио идёт влево - карта едет вправо.
	if (left_pressed && !right_pressed) {
		return UserInput::MAP_RIGHT;
	}
	if (right_pressed && !left_pressed) {
		return UserInput::MAP_LEFT;
	}
	if (jump_pressed) {
		return UserInput::MARIO_JUMP;
	}
	return UserInput::NO_INPUT;
}

void QtKeyBoard::off() {
	if (is_on) {
		QCoreApplication::instance()->removeEventFilter(this);
		is_on = false;
	}
	release_keys();
}

void QtKeyBoard::on() {
	if (!is_on) {
		// Фильтр на уровне приложения видит клавиши, какое бы окно их ни получило.
		QCoreApplication::instance()->installEventFilter(this);
		is_on = true;
	}
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
bool QtKeyBoard::eventFilter(QObject* watched, QEvent* event) {
	switch (event->type()) {
		case QEvent::KeyPress:
			process_key(static_cast<QKeyEvent*>(event)->key(), true);
			break;
		case QEvent::KeyRelease:
			// При удержании клавиши система шлёт повторы "отпущена - нажата". 
			// Это не настоящее отпускание.
			if (!static_cast<QKeyEvent*>(event)->isAutoRepeat()) {
				process_key(static_cast<QKeyEvent*>(event)->key(), false);
			}
			break;
		case QEvent::WindowDeactivate:
			// Окно потеряло фокус: отпускания клавиш до нас уже не дойдут.
			release_keys();
			break;
		case QEvent::Close:
			// Окно закрыли крестиком.
			exit_requested = true;
			break;
		default:
			break;
	}
	// Событие не поглощаем: пусть Qt обработает его как обычно.
	return QObject::eventFilter(watched, event);
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
void QtKeyBoard::process_key(const int key, const bool pressed) noexcept {
	if (is_left_key(key)) {
		left_pressed = pressed;
	} else if (is_right_key(key)) {
		right_pressed = pressed;
	} else if (is_jump_key(key)) {
		if (pressed && !jump_pressed) {
			jump_requested = true;
		}
		jump_pressed = pressed;
	} else if (is_exit_key(key) && pressed) {
		exit_requested = true;
	}
}

void QtKeyBoard::release_keys() noexcept {
	left_pressed = false;
	right_pressed = false;
	jump_pressed = false;
	jump_requested = false;
}
