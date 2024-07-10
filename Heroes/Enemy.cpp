#include "Enemy.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Enemy::Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id) : Character(position, size, id)
			{

			}

			Enemy::~Enemy()
			{

			}

			void Enemy::collide(Entity* other, Math::CoordinateF intersection)
			{
				if (other->getID() == platform)
				{
					
					velocity.y = 0;
				}
			}
		}
	}
}