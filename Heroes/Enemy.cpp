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
		}
	}
}