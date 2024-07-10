#include "Goblin.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Goblin::Goblin(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(GOBLIN_SIZE_X, GOBLIN_SIZE_Y), goblin)
			{
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
				sprite.addNewAnimation(GraphicalElements::attack, GOBLIN_ATTACK_PATH, 8, 1);
				sprite.addNewAnimation(GraphicalElements::death, GOBLIN_DEATH_PATH, 4, 1.7);
			}

			void Goblin::update(const float dt)
			{
				position.y += velocity.y + (GRAVITY * dt * dt) / 2.0f;
				velocity.y += GRAVITY * dt;

				updateSprite(dt);
			}

			void Goblin::updateSprite(const float dt)
			{
				sprite.update(GraphicalElements::idle, isFacingRight(), Math::CoordinateF(150, 50), dt);
			}
		}
	}
}