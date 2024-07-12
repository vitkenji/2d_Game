#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Projectiles
	{
		class Projectile : public MovingEntity
		{
		protected:
		public:
			Projectile(Math::CoordinateF position, Math::CoordinateF size, ID id);
			virtual ~Projectile();

			virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;

		};
	}
}