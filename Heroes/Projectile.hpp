#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Projectiles
	{
		class Projectile : public MovingEntity
		{
		protected:
			bool shot;

		public:
			Projectile(Math::CoordinateF position, Math::CoordinateF size, ID id);
			virtual ~Projectile();

			void activateProjectile();
			void render();
			virtual void update(const float dt) = 0;
			virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
			
		};
	}
}