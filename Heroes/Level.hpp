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
#include "FlyingEye.hpp"
#include "Fire.hpp"
#include "Box.hpp"
#include "Hud.hpp"
#include "Water.hpp"
#include "Mud.hpp"

namespace States
{
	
	class Level : public State
	{
	private:
		Managers::CollisionManager collisionManager;
		Managers::GraphicManager* pGraphicManager;

		Entities::Characters::Player* player;
		Entities::Characters::Enemies::Skeleton* skeleton;
		Entities::Characters::Enemies::Goblin* goblin;
		Entities::Characters::Enemies::Mushroom* mushroom;
		Entities::Characters::Enemies::FlyingEye* flyingEye;
		Control::PlayerControl* pPlayerControl;
		GraphicalElements::SingleFrameAnimation background;

		Entities::Obstacles::Fire* fire;
		Entities::Obstacles::Water* water;
		Entities::Obstacles::Box* box;
		Entities::Obstacles::Mud* mud;

		List::EntityList staticEntitiesList;
		List::EntityList movingEntitiesList;
	
		GraphicalElements::Hud hud;

		bool resume;

	public:
		Level(StateMachine* pStateMachine);
		~Level();
		void resetState();
		void update(const float dt);
		void render();
		void endLevel();
		void restartLevel();
		void setResume(bool resume);
		int getPlayerPoints();
	};
	
}