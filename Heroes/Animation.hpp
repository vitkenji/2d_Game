#pragma once
#include "GraphicManager.hpp"

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