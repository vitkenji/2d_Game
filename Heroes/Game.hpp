#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "paths.h"
#include "constants.h"
#include "Player.hpp"
#include "GraphicManager.hpp"

namespace States
{
	class Game
	{
	private:
		sf::Clock clock;
		float dt;
		Managers::GraphicManager* pGraphic;
		
	public:
		Game();
		~Game();
		void execute();
	};
}