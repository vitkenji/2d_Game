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
#include "Goblin.hpp"
#include "EntityList.hpp"
#include "Platform.hpp"
#include "CollisionManager.hpp"
#include "Bomb.hpp"
#include "StateMachine.hpp"
#include "MainMenu.hpp"
#include "Level.hpp"

namespace States
{
	class Game : public StateMachine
	{
	private:
		sf::Clock clock;
		float dt;
		Managers::GraphicManager* pGraphic;
		Managers::EventManager* pEvent;
		
	public:
		Game();
		~Game();
		void execute();
		void quit();
	};
}