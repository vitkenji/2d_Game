#include "Goblin.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Goblin::Goblin(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(GOBLIN_SIZE_X, GOBLIN_SIZE_Y), goblin)
			{
				i = bombList.begin();
				bombCooldown = 10;
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

			//maybe in enemy class
			void Goblin::update(const float dt)
			{
				Math::CoordinateF distance = Math::CoordinateF(fabs(pPlayer->getPosition().x - this->position.x), fabs(pPlayer->getPosition().y - this->position.y));
				if (distance.x < 400)
				{
  					shoot();
				}


				manageTakeHitCooldown(dt);
				if (life <= 0 && deathCooldown == 0)
				{
					isDying = true;
				}
				manageDeathCooldown(dt);

				position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
				velocity.y += acceleration.y * dt;

				updateSprite(dt);
			}

			void Goblin::shoot()
			{
				Projectiles::Bomb* bomb = nullptr;

				if (i == bombList.end() || i == bombList.end()--)
				{
					i = bombList.begin();
				}

				bomb = *i;
				++i; 

				bomb->activateProjectile(); 
			}

		}
	}
}