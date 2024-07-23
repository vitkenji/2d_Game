#pragma once
#include "GraphicManager.hpp"
#include "std.h"

namespace GraphicalElements
{
	class Animation
	{
	protected:
		sf::RectangleShape body;
		static Managers::GraphicManager* pGraphic;

	public:
		Animation();
		~Animation();
		virtual void render();

	};
}