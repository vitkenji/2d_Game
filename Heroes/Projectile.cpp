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
			//std::cout << "activated";
			this->active = true;
			this->shot = true;

		}

		void Projectile::deactivateProjectile()
		{
			std::cout << "deactivated";
			this->active = false;
			this->shot = false;
		}

		void Projectile::render()
		{
			if (shot)
			{
				sprite.render();
			}
		}

		bool Projectile::wasShot()
		{
			return this->shot;
		}

		void Projectile::resetSprite(const float dt)
		{
			sprite.update(GraphicalElements::idle, isFacingRight(), this->position, dt);
		}

	}
}