#pragma once
#include "Projectile.hpp"

namespace Entities
{
	namespace Projectiles
	{
		class Bomb : public Projectile
		{
		private:

		public:
			Bomb(Math::CoordinateF position);
			virtual ~Bomb();
			
			void explode();
			void addAnimations();
			void update(const float dt);
			void updateSprite(const float dt);
			void collide(Entity* other, Math::CoordinateF intersection);
			void checkCollision(Entity* other, Math::CoordinateF intersection);
		};
	}
}