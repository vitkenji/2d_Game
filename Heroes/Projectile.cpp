#include "Projectile.hpp"

namespace Entities
{
	namespace Projectiles
	{
		
		Projectile::Projectile(Math::CoordinateF position, Math::CoordinateF size, ID id) : MovingEntity(position, size, id), cooldown(0)
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
			//std::cout << "activated" << std::endl;
			this->active = true;
			this->shot = true;
		}

		void Projectile::deactivateProjectile()
		{
			if (shot)
			{
				this->active = false;
			}
			this->shot = false;
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