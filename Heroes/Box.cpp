#include "Box.hpp"

namespace Entities
{
	namespace Obstacles
	{
		Box::Box(Math::CoordinateF position) : MovingEntity(position, Math::CoordinateF(BOX_WIDTH, BOX_HEIGHT), box)
		{
			addAnimations();
		}

		Box::~Box()
		{

		}

		void Box::addAnimations()
		{
			sprite.addNewAnimation(GraphicalElements::idle, BOX_PATH, 1, 0.1);
		}

		void Box::update(const float dt)
		{
			fallToGravity(dt);
			position.x += velocity.x * dt;
			updateSprite(dt);
		}


		void Box::updateSprite(const float dt)
		{
			sprite.update(GraphicalElements::idle, true, this->position, dt);
		}

		void Box::collide(Entity* other, Math::CoordinateF intersection)
		{
			checkCollision(other, intersection);
		}

		void Box::checkCollision(Entity* other, Math::CoordinateF intersection)
		{
			if (other->getID() == platform)
			{
				velocity.y = 0;
			}
				
			if (other->getID() == player)
			{
				MovingEntity* ptr = dynamic_cast<MovingEntity*>(other);
				if (intersection.y > 0)
				{
					velocity.x = ptr->getVelocity().x;
				}
				
			}
			
		}
	}
}