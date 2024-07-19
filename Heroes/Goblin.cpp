#include "Goblin.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Goblin::Goblin(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(GOBLIN_SIZE_X, GOBLIN_SIZE_Y), goblin)
			{
				bomb = new Projectiles::Bomb(position);
				bombCooldown = 0;
				attackAnimationTime = 0;
				swordDistance = 5;
				addAnimations();
				canShoot = true;

			}

			Goblin::~Goblin()
			{
			}

			void Goblin::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, GOBLIN_IDLE_PATH, 4, 0.2);
				sprite.addNewAnimation(GraphicalElements::run, GOBLIN_RUN_PATH, 8, 0.2);
				sprite.addNewAnimation(GraphicalElements::takeHit, GOBLIN_TAKEHIT_PATH, 4, 0.2);
				sprite.addNewAnimation(GraphicalElements::attack, GOBLIN_ATTACK_PATH, 12, 0.2);
				sprite.addNewAnimation(GraphicalElements::death, GOBLIN_DEATH_PATH, 4, 0.45);
			}

			void Goblin::update(const float dt)
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
					if(isAttacking)
					{
						attackAnimationTime += dt;

					}

					if (attackAnimationTime >= 1.2)
					{
	
						isAttacking = false;
						if (canShoot)
						{
							shoot(dt);
							//std::cout << "shooted" << std::endl;
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
							//std::cout << "now can shoot:" << std::endl;
						}
					}
				}

				manageTakeHitCooldown(dt);
				if (life <= 0 && deathCooldown == 0)
				{
					isDying = true;
					bomb->setActive(false);
				}
				manageDeathCooldown(dt);

				fallToGravity(dt);
				updateSprite(dt);
			}

			void Goblin::shoot(const float dt)
			{
					bomb->resetSprite(dt);
					bomb->activateProjectile();
					if (facingRight)
					{
						bomb->setPosition(Math::CoordinateF(this->position.x + 20, this->position.y - 10));
					}
					else
					{
						bomb->setPosition(Math::CoordinateF(this->position.x - 20, this->position.y - 10));
					}

					Math::CoordinateF bombVelocity = Math::CoordinateF((pPlayer->getPosition().x - this->position.x)/1.3, -6);

					bomb->setVelocity(bombVelocity);
				
			}

			void Goblin::noticePlayer(Math::CoordinateF distance)
			{

			}

			void Goblin::collide(Entity* other, Math::CoordinateF intersection)
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