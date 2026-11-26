target_sources(${PROJECT_NAME}
	PRIVATE
		qt_box.cpp
		qt_damage_box.cpp
		qt_enemy.cpp
		qt_flyable_enemy.cpp
		qt_heal_kit.cpp
		qt_jumpable_enemy.cpp
		qt_full_box.cpp
		qt_mario.cpp
		qt_ship.cpp
		qt_platform.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
