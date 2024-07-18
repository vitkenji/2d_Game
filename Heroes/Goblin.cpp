#include "Goblin.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Goblin::Goblin(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(GOBLIN_SIZE_X, GOBLIN_SIZE_Y), goblin)
			{
				for (int i = 0; i < 2; i++)
				{
					Projectiles::Bomb* bomb = new Projectiles::Bomb(Math::CoordinateF(position.x - 50, position.y - 40));
					bombList.push_back(bomb);
				}
				
				i = bombList.begin();
				bombCooldown = 0;
				attackAnimationTime = 0;
				swordDistance = 5;
				addAnimations();
			}

			Goblin::~Goblin()
			{
			}

			void Goblin::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, GOBLIN_IDLE_PATH, 4, 1.3);
				sprite.addNewAnimation(GraphicalElements::run, GOBLIN_RUN_PATH, 8, 1);
				sprite.addNewAnimation(GraphicalElements::takeHit, GOBLIN_TAKEHIT_PATH, 4, 1.2);
				sprite.addNewAnimation(GraphicalElements::attack, GOBLIN_ATTACK_PATH, 12, 1);
				sprite.addNewAnimation(GraphicalElements::death, GOBLIN_DEATH_PATH, 4, 1.7);
			}

			void Goblin::update(const float dt)
			{
				Math::CoordinateF distance = Math::CoordinateF(fabs(pPlayer->getPosition().x - this->position.x), fabs(pPlayer->getPosition().y - this->position.y));
				if (distance.x < 400)
				{
					if (attackAnimationTime == 0)
					{
						isAttacking = true;
					}
					attackAnimationTime += dt;
					if (attackAnimationTime >= 10)
					{
						attackAnimationTime = 0;
						isAttacking = false;
						shoot();
						bombCooldown += dt;
						if (bombCooldown >= 8)
						{
							(*i)->deactivateProjectile();
							bombCooldown = 0;
						}
					}
				}

				manageTakeHitCooldown(dt);
				if (life <= 0 && deathCooldown == 0)
				{
					isDying = true;
				}
				manageDeathCooldown(dt);

				fallToGravity(dt);
				updateSprite(dt);
			}

			void Goblin::shoot()
			{
				Projectiles::Bomb* bomb = nullptr;
				std::cout << bombList.size() << std::endl;
				if (i == bombList.end() || i == bombList.end()--)
				{
					i = bombList.begin();
				}

				bomb = *i;
				++i; 

				bomb->activateProjectile(); 

				if (facingRight)
				{
					//bomb->setVelocity(Math::CoordinateF(20, -2));
				}
				else
				{
					//bomb->setVelocity(Math::CoordinateF(-20, -2));
				}
			}

			void Goblin::noticePlayer(Math::CoordinateF distance)
			{

			}

		}
	}
}