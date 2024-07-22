#include "Fire.hpp"

namespace Entities
{
	namespace Obstacles
	{
		Fire::Fire(Math::CoordinateF position) : MovingEntity(position, Math::CoordinateF(FIRE_WIDTH, FIRE_HEIGHT), fire)
		{
			addAnimations();
			damage = 20;
		}

		Fire::~Fire()
		{

		}

		void Fire::addAnimations()
		{
			sprite.addNewAnimation(GraphicalElements::idle, FIRE_PATH, 8, 0.1);
		}

		void Fire::update(const float dt)
		{
			updateSprite(dt);
			fallToGravity(dt);
		}

		void Fire::updateSprite(const float dt)
		{
			sprite.update(GraphicalElements::idle, true, this->position, dt);
		}

		void Fire::collide(Entity* other, Math::CoordinateF intersection)
		{
			checkCollision(other, intersection);
		}

		void Fire::checkCollision(Entity* other, Math::CoordinateF intersection)
		{
			if (other->getID() == platform)
			{
				velocity.y = 0;

			}
		}
	}
}
