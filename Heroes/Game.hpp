#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "paths.h"
#include "constants.h"
#include "Player.hpp"
#include "GraphicManager.hpp"
#include "PlayerControl.hpp"
#include "SingleFrameAnimation.hpp"
#include "EventManager.hpp"
#include "Skeleton.hpp"

namespace States
{
	class Game
	{
	private:
		sf::Clock clock;
		float dt;
		Managers::GraphicManager* pGraphic;
		Managers::EventManager* pEvent;
		Entities::Characters::Player player;
		Entities::Characters::Enemies::Skeleton skeleton;
		Control::PlayerControl* pPlayerControl;
		GraphicalElements::SingleFrameAnimation background;
		
	public:
		Game();
		~Game();
		void execute();
	};
}