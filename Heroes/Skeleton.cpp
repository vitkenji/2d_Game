#include "Skeleton.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			
			Skeleton::Skeleton(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(SKELETON_SIZE_X, SKELETON_SIZE_Y), skeleton)
			{
				swordDistance = 8;
				addAnimations();
			}

			Skeleton::~Skeleton()
			{

			}

			void Skeleton::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, SKELETON_IDLE_PATH, 4, 1.8);
				sprite.addNewAnimation(GraphicalElements::attack, SKELETON_ATTACK_PATH, 8, 0.9);
				sprite.addNewAnimation(GraphicalElements::death, SKELETON_DEATH_PATH, 4, 1.8);
				sprite.addNewAnimation(GraphicalElements::run, SKELETON_RUN_PATH, 4, 1);
				sprite.addNewAnimation(GraphicalElements::takeHit, SKELETON_TAKEHIT_PATH, 4, 1.5);

			}

			//maybe in enemy class
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

				position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
				velocity.y += acceleration.y * dt;

				updateSprite(dt);
				
			}

	
			void Skeleton::walk()
			{
				srand(time(NULL));
				int direction = rand() % 40;
				
				Math::CoordinateF distance = Math::CoordinateF(fabs(pPlayer->getPosition().x - this->position.x), fabs(pPlayer->getPosition().y - this->position.y));
				if (distance.x < 300)
				{				
					if (distance.x <= 60)
					{
						velocity.x = 0;
					}
					if (pPlayer->getPosition().x > this->position.x)
					{
						isWalking = true;
						isAttacking = false;
						setFacingRight(true);
						velocity.x = 8;
					}
					else
					{
						isWalking = true;
						isAttacking = false;
						setFacingRight(false);
						velocity.x = -8;
					}
				}

				else
				{
					std::cout << direction << std::endl;
					if (direction > 0 && direction <= 13)
					{
						isWalking = true;
						isAttacking = false;
						setFacingRight(false);
						velocity.x = -5;
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
						velocity.x = 5;
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