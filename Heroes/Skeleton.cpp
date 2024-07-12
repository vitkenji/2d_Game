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
				if (isTakingHit == true)
				{
					cooldown += dt;
					if (cooldown >= 10)
					{
						cooldown = 0;
						isTakingHit = false;

					}
				}
				if (life <= 0 && deathCooldown == 0)
				{
					isDying = true;
					deathCooldown += dt;
				}
				if (isDying)
				{
					deathCooldown += dt;
					if (deathCooldown >= 6)
					{
						isDying = false;
						active = false;
						
					}

				}

				position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
				velocity.y += acceleration.y * dt;

				updateSprite(dt);
			}

		}
	}
}