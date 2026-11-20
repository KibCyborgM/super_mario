#pragma once

namespace biv {
	/**
		Какой картинкой рисуется объект. 
		В консольной версии эту роль играет символ-кисть (get_brush).
	*/
	enum class QtSprite {
		BOX,
		CLOUD,
		EMPTY_BOX,
		ENEMY,
		FLYABLE_ENEMY,
		FULL_BOX,
		JUMPABLE_ENEMY,
		MARIO,
		MONEY,
		PLATFORM,
		SHIP,
		WATER
	};
}
