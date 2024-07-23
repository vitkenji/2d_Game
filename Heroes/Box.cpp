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
			acceleration.x = velocity.x * -1 * 0.8;
			if (velocity.x < 50 && velocity.x > -50)
			{
				velocity.x = 0;
			}
			velocity.x += acceleration.x * dt;
			position.x += velocity.x * dt;
			fallToGravity(dt);
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
				std::cout << "X: " << intersection.x << std::endl;
				std::cout << "Y: " << intersection.y << std::endl;

				MovingEntity* ptr = dynamic_cast<MovingEntity*>(other);
				
				if (intersection.x < 0.f && intersection.y < 0.f)
				{
					velocity.x = 0;
				}
				
				if (intersection.x < 0.f && intersection.y < -25.f)
				{
					velocity.x = PLAYER_VELOCITY_X / 2;
					if (!ptr->isFacingRight())
					{
						velocity.x *= -1;
					}

				}

			}
			
		}
	}
}