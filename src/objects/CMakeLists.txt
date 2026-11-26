target_sources(${PROJECT_NAME}
	PRIVATE
		damage_box.cpp
		flyable_enemy.cpp
		heal_kit.cpp
		jumpable_enemy.cpp
		full_box.cpp
		enemy.cpp
		mario.cpp
		money.cpp
		platform.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
