#include "Projectile.hpp"

namespace Entities
{
	namespace Projectiles
	{
		
		Projectile::Projectile(Math::CoordinateF position, Math::CoordinateF size, ID id) : MovingEntity(position, size, id)
		{
			this->active = true;
			this->shot = false;
			acceleration = Math::CoordinateF(0, GRAVITY);
		}

		Projectile::~Projectile()
		{
		}

		void Projectile::activateProjectile()
		{
			if (facingRight)
			{
				this->velocity.x = 20;
			}
			else
			{
				this->velocity.x = -20;
			}
			this->active = true;
			this->shot = true;
		}

		void Projectile::render()
		{
			if (shot)
			{
				sprite.render();
			}
		}
	}
}