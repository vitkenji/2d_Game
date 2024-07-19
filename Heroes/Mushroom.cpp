#include "Mushroom.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Mushroom::Mushroom(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(MUSHROOM_SIZE_X, MUSHROOM_SIZE_Y), mushroom)
			{
				addAnimations();
			}

			Mushroom::~Mushroom()
			{

			}

			void Mushroom::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, MUSHROOM_IDLE_PATH, 4, 0.1);
				sprite.addNewAnimation(GraphicalElements::takeHit, MUSHROOM_TAKEHIT_PATH, 4, 0.1);
				sprite.addNewAnimation(GraphicalElements::death, MUSHROOM_DEATH_PATH, 4, 0.43);
				sprite.addNewAnimation(GraphicalElements::run, MUSHROOM_RUN_PATH, 8, 0.1);
				sprite.addNewAnimation(GraphicalElements::attack, MUSHROOM_ATTACK_PATH, 8, 0.1);

			}

			void Mushroom::update(const float dt)
			{
				manageTakeHitCooldown(dt);
				if (life <= 0 && deathCooldown == 0)
				{
					isDying = true;
				}
				manageDeathCooldown(dt);
				walk();
				position.x += velocity.x * dt;

				fallToGravity(dt);
				updateSprite(dt);

			}

			void Mushroom::noticePlayer(Math::CoordinateF distance)
			{
				if (pPlayer->getPosition().x > this->position.x)
				{
					isWalking = true;
					isAttacking = false;
					setFacingRight(true);
					if (distance.x > 49)
					{
						velocity.x = 70;
					}
					else
					{
						isAttacking = true;
						velocity.x = 0;
					}
				}
				else
				{
					isWalking = true;
					isAttacking = false;
					setFacingRight(false);
					if (distance.x > 49)
					{
						velocity.x = -70;
					}
					else
					{
						isAttacking = true;
						velocity.x = 0;
					}
				}
			}

			void Mushroom::walk()
			{
				srand(time(NULL));
				int direction = rand() % 40;

				Math::CoordinateF distance = Math::CoordinateF(fabs(pPlayer->getPosition().x - this->position.x), fabs(pPlayer->getPosition().y - this->position.y));
				if (distance.x < 300)
				{
					noticePlayer(distance);
				}

				else
				{

					if (direction > 0 && direction <= 13)
					{
						isWalking = true;
						isAttacking = false;
						setFacingRight(false);
						velocity.x = -35;
					}
					else if (direction > 13 && direction <= 20)
					{
						isWalking = false;
						velocity.x = 0;
					}
					else if (direction > 20 && direction <= 33)
					{
						isWalking = true;
						isAttacking = false;
						setFacingRight(true);
						velocity.x = 35;
					}
					else
					{
						isWalking = false;
						velocity.x = 0;
					}

				}

			}

			

		}
	}
}