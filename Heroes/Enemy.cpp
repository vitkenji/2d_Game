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

			void Enemy::setPlayer(Player* pPlayer)
			{
				this->pPlayer = pPlayer;

			}

			void Enemy::collide(Entity* other, Math::CoordinateF intersection)
			{
				checkCollision(other, intersection);
				if (other->getID() == platform)
				{
					velocity.y = 0;
				}
				if (other->getID() == player)
				{
					isAttacking = true;
				}
			}

			void Enemy::checkCollision(Entity* other, Math::CoordinateF intersection)
			{
				if (other->getID() == platform)
				{
					velocity.y = 0;
				}

				if (other->getID() == player)
				{
					if (intersection.x < 0.f)
					{
						if (velocity.x > 0)
						{
							position.x -= 2;
						}
						else if (velocity.x < 0)
						{
							position.x += 2;
						}
						velocity.x = 0;

					}
				}
			}
		}
	}
}