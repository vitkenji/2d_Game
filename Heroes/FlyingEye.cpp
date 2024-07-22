#include "FlyingEye.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			FlyingEye::FlyingEye(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(FLYINGEYE_SIZE_X, FLYINGEYE_SIZE_Y), flyingeye)
			{
				addAnimations();
			}

			FlyingEye::~FlyingEye()
			{

			}

			void FlyingEye::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, FLYINGEYE_IDLE_PATH, 8, 0.2);
				sprite.addNewAnimation(GraphicalElements::run, FLYINGEYE_RUN_PATH, 8, 0.2);
				sprite.addNewAnimation(GraphicalElements::takeHit, FLYINGEYE_TAKEHIT_PATH, 4, 0.2);
				sprite.addNewAnimation(GraphicalElements::attack, FLYINGEYE_ATTACK_PATH, 6, 0.2);
				sprite.addNewAnimation(GraphicalElements::death, FLYINGEYE_DEATH_PATH, 4, 0.45);
			}

			void FlyingEye::update(const float dt)
			{
				Math::CoordinateF distance = Math::CoordinateF(fabs(pPlayer->getPosition().x - this->position.x), fabs(pPlayer->getPosition().y - this->position.y));
				if (distance.x < 400)
				{

					if (pPlayer->getPosition().x > this->position.x)
					{
						setFacingRight(true);
					}
					else
					{
						setFacingRight(false);
					}

					if (canShoot)
					{
						isAttacking = true;
					}
					if (isAttacking)
					{
						attackAnimationTime += dt;

					}

					if (attackAnimationTime >= 1.2)
					{

						isAttacking = false;
						if (canShoot)
						{
							shoot(dt);
							canShoot = false;
						}
						attackAnimationTime = 0;
					}
					if (!canShoot)
					{
						bombCooldown += dt;

						if (bombCooldown >= 5)
						{
							bombCooldown = 0;
							canShoot = true;
						}
					}
				}

				manageTakeHitCooldown(dt);
				if (life <= 0)
				{
					isDying = true;
					fallToGravity(dt);
				}
				manageDeathCooldown(dt);

			
				updateSprite(dt);
			}

			void FlyingEye::shoot(const float dt)
			{
			}

			void FlyingEye::noticePlayer(Math::CoordinateF distance)
			{

			}

			void FlyingEye::collide(Entity* other, Math::CoordinateF intersection)
			{
				Player* pPlayer = dynamic_cast<Player*>(other);
				checkCollision(other, intersection);
				if (other->getID() == platform)
				{
					velocity.y = 0;
				}
				if (other->getID() == player)
				{
					if (intersection.x < 0.f && pPlayer->getIsAttacking())
					{
						isTakingHit = true;
						takeDamage(pPlayer->getDamage());
					}
				}
			}
		}
	}
}