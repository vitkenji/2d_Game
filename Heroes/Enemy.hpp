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
				bool isDying;
				float deathCooldown;

			public:
				Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id);
				virtual ~Enemy();

				void setPlayer(Player* pPlayer);
				void manageDeathCooldown(const float dt);
				virtual void update(const float dt) = 0;
				virtual void updateSprite(const float dt);
				virtual void collide(Entity* other, Math::CoordinateF intersection);
				void checkCollision(Entity* other, Math::CoordinateF intersection);
			};
		
		}
	}
}