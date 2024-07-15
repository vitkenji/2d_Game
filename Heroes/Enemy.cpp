#include "Enemy.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Enemy::Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id) : Character(position, size, id), isDying(false), deathCooldown(0), pPlayer()
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
				Player* pPlayer = dynamic_cast<Player*>(other);
				checkCollision(other, intersection);
				if (other->getID() == platform)
				{
					velocity.y = 0;
				}
				if (other->getID() == player)
				{
					isAttacking = true;
					if (intersection.x < 0.f && pPlayer->getIsAttacking())
					{
						isTakingHit = true;
						takeDamage(pPlayer->getDamage());
					}
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
							position.x -= 1;
						}
						else if (velocity.x < 0)
						{
							position.x += 1;
						}
						velocity.x = 0;

					}
				}
			}

			void Enemy::updateSprite(const float dt)
			{
				if (isDying)
				{
					sprite.update(GraphicalElements::death, isFacingRight(), this->position, dt);
				}
				else if (isAttacking && !isTakingHit)
				{
					sprite.update(GraphicalElements::attack, isFacingRight(), this->position, dt);
				}
				else if (isWalking && !isAttacking)
				{
					sprite.update(GraphicalElements::run, isFacingRight(), this->position, dt);
				}

				else if (isTakingHit)
				{
					sprite.update(GraphicalElements::takeHit, isFacingRight(), position, dt);
				}

				else
				{
					sprite.update(GraphicalElements::idle, isFacingRight(), this->position, dt);
				}
			}

			void Enemy::manageDeathCooldown(const float dt)
			{
				if (isDying)
				{
					deathCooldown += dt;
					if (deathCooldown >= 6)
					{
						isDying = false;
						active = false;

					}

				}
			}

		}
	}
}