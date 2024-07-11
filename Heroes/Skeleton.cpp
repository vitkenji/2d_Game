#include "Skeleton.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Skeleton::Skeleton(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(SKELETON_SIZE_X, SKELETON_SIZE_Y), skeleton), swordDistance(5)
			{
				addAnimations();
			}

			Skeleton::~Skeleton()
			{

			}

			void Skeleton::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, SKELETON_IDLE_PATH, 4, 1.8);
				sprite.addNewAnimation(GraphicalElements::attack, SKELETON_ATTACK_PATH, 8, 1);
				sprite.addNewAnimation(GraphicalElements::death, SKELETON_DEATH_PATH, 4, 1.8);
				sprite.addNewAnimation(GraphicalElements::run, SKELETON_RUN_PATH, 4, 1);
				sprite.addNewAnimation(GraphicalElements::takeHit, SKELETON_TAKEHIT_PATH, 4, 1);

			}

			//maybe in enemy class
			void Skeleton::update(const float dt)
			{
				position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
				velocity.y += acceleration.y * dt;

				updateSprite(dt);
			}

			//maybe in enemy class
			void Skeleton::updateSprite(const float dt)
			{
				if (isAttacking)
				{
					sprite.update(GraphicalElements::attack, isFacingRight(), this->position, dt);
				}
				else if (isWalking)
				{
					sprite.update(GraphicalElements::run, isFacingRight(), this->position, dt);
				}
				else
				{
					sprite.update(GraphicalElements::idle, isFacingRight(), this->position, dt);
				}
			}

		}
	}
}