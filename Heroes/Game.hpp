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

namespace States
{
	class Game
	{
	private:
		sf::Clock clock;
		float dt;
		Managers::GraphicManager* pGraphic;
		Managers::EventManager* pEvent;
		Managers::CollisionManager collisionManager;

		Entities::Characters::Player player;
		Entities::Characters::Enemies::Skeleton skeleton;
		Entities::Characters::Enemies::Goblin goblin;
		
		Control::PlayerControl* pPlayerControl;
		GraphicalElements::SingleFrameAnimation background;

		List::EntityList staticEntitiesList;
		List::EntityList movingEntitiesList;
	
		
	public:
		Game();
		~Game();
		void execute();
	};
}