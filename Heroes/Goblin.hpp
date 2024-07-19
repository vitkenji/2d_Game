#pragma once
#include "Enemy.hpp"
#include "Bomb.hpp"
#include <list>
#include <vector>
namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Goblin : public Enemy
			{
			private:
				float bombCooldown;
				float attackAnimationTime;
				bool canShoot;

			public:
				Projectiles::Bomb* bomb;

				Goblin(Math::CoordinateF position);
				virtual ~Goblin();

				void addAnimations();
				void update(const float dt);
				void shoot(const float dt);
				void noticePlayer(Math::CoordinateF distance);
	
			};
		}
	}
}