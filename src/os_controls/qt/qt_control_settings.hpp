#pragma once

#include "os_control_settings.hpp"

namespace biv {
	/**
		В консоли этот класс прячет курсор и возвращает его в начало экрана.
		В окне Qt курсора консоли нет, поэтому настраивать здесь нечего:
		класс нужен только для того, чтобы игровой цикл остался прежним.
	*/
	class QtControlSettings : public OSControlSettings {
		public:
			void init() override;
			void set_cursor_start_position() override;
	};
}
