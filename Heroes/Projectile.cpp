#include "Projectile.hpp"

namespace Entities
{
	namespace Projectiles
	{
		
		Projectile::Projectile(Math::CoordinateF position, Math::CoordinateF size, ID id) : MovingEntity(position, size, id)
		{

		}

		Projectile::~Projectile()
		{
		}
	}
}