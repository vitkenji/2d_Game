#pragma once
#include "State.hpp"
#include "EntityList.hpp"
#include "CollisionManager.hpp"
#include "Player.hpp"
#include "PlayerControl.hpp"
#include "Skeleton.hpp"
#include "Goblin.hpp"
#include "Platform.hpp"
#include "Bomb.hpp"
#include "Mushroom.hpp"


namespace States
{
	
	class Level : public State
	{
	private:
		Managers::CollisionManager collisionManager;
		Managers::GraphicManager* pGraphicManager;

		Entities::Characters::Player player;
		Entities::Characters::Enemies::Skeleton skeleton;
		Entities::Characters::Enemies::Goblin goblin;
		Entities::Characters::Enemies::Mushroom mushroom;

		Control::PlayerControl* pPlayerControl;
		GraphicalElements::SingleFrameAnimation background;

		List::EntityList staticEntitiesList;
		List::EntityList movingEntitiesList;
	
	public:
		Level(StateMachine* pStateMachine);
		~Level();
		void resetState();
		void update(const float dt);
		void render();
	};
	
}