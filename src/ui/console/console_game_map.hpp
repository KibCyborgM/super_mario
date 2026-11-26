#pragma once

#include <vector>

#include "game_map.hpp"
#include "console_mario.hpp"
#include "console_ui_obj.hpp"

namespace biv {
	class ConsoleGameMap : public GameMap {
		private:
			char** map;
			
			std::vector<ConsoleUIObject*> objs;
			ConsoleMario* mario_obj = nullptr;
			
		public:
			ConsoleGameMap(const int height, const int width);
			~ConsoleGameMap();
			
			void add_obj(ConsoleUIObject*);
			void add_mario(ConsoleMario*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(ConsoleUIObject*);
			void remove_objs() override;
			void show() const noexcept override;
	};
}
