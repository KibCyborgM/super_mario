#include "another_second_level.hpp"

#include "third_level.hpp"

using biv::AnotherSecondLevel;

AnotherSecondLevel::AnotherSecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool AnotherSecondLevel::is_final() const noexcept {
	return false;
}

biv::GameLevel* AnotherSecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ThirdLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void AnotherSecondLevel::init_data() {
	ui_factory->create_mario({30, 10}, 3, 3);
	
    ui_factory->create_ship({5, 20}, 30, 2);

	ui_factory->create_ship({45, 12}, 15, 6);
	ui_factory->create_full_box({50, 4}, 5, 3);

	ui_factory->create_ship({70, 27}, 50, 3);
    ui_factory->create_ship({110, 20}, 5, 9);
    ui_factory->create_ship({115, 12}, 5, 18);
	ui_factory->create_ship({120, 9}, 20, 21);
	

	ui_factory->create_ship({150, 18}, 45, 2);
	ui_factory->create_full_box({180, 10}, 5, 3);

    ui_factory->create_ship({230, 20}, 15, 7);

    ui_factory->create_flyable_enemy({20, 5}, 3, 2);
	ui_factory->create_jumpable_enemy({47, 5}, 3, 2);
    ui_factory->create_enemy({80, 5}, 3, 2);
	ui_factory->create_enemy({95, 5}, 3, 2);
    ui_factory->create_enemy({130, 3}, 3, 2);
    ui_factory->create_enemy({165, 5}, 3, 2);
	ui_factory->create_enemy({170, 5}, 3, 2);
}
