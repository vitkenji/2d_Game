#include "Skeleton.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			
			Skeleton::Skeleton(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(SKELETON_SIZE_X, SKELETON_SIZE_Y), skeleton)
			{
				damage = 8;
				addAnimations();
			}

			Skeleton::~Skeleton()
			{

			}

			void Skeleton::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, SKELETON_IDLE_PATH, 4, 0.19);
				sprite.addNewAnimation(GraphicalElements::attack, SKELETON_ATTACK_PATH, 8, 0.15);
				sprite.addNewAnimation(GraphicalElements::death, SKELETON_DEATH_PATH, 4, 0.43);
				sprite.addNewAnimation(GraphicalElements::run, SKELETON_RUN_PATH, 4, 0.1);
				sprite.addNewAnimation(GraphicalElements::takeHit, SKELETON_TAKEHIT_PATH, 4, 0.2);

			}

			void Skeleton::update(const float dt)
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

			void Skeleton::noticePlayer(Math::CoordinateF distance)
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
	
			void Skeleton::walk()
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