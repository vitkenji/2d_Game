#pragma once
#include "Character.hpp"
#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Enemy : public Character
			{
			protected:
				Player* pPlayer;

			public:
				Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id);
				~Enemy();

				void setPlayer(Player* pPlayer);

				virtual void update(const float dt) = 0;
				virtual void collide(Entity* other, Math::CoordinateF intersection);
				void checkCollision(Entity* other, Math::CoordinateF intersection);
			};
		
		}
	}
}