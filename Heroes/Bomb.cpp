#include "Bomb.hpp"

namespace Entities
{
	namespace Projectiles
	{
		Bomb::Bomb(Math::CoordinateF position) : Projectile(position, Math::CoordinateF(BOMB_SIZE_X, BOMB_SIZE_Y), bomb)
		{
			
			addAnimations();
		}

		Bomb::~Bomb() {}

		void Bomb::addAnimations()
		{
			sprite.addNewAnimation(GraphicalElements::idle, BOMB_IDLE_PATH, 1, 1);
			sprite.addNewAnimation(GraphicalElements::explode, BOMB_SHOT_PATH, 19, 1.5);
		}

		void Bomb::update(const float dt)
		{
			fallToGravity(dt);

			position.x += velocity.x * dt;
			
			updateSprite(dt);
		}

		void Bomb::updateSprite(const float dt)
		{
			if (shot)
			{
				sprite.update(GraphicalElements::explode, isFacingRight(), this->position, dt);
			}
			else
			{
				sprite.update(GraphicalElements::idle, isFacingRight(), this->position, dt);
			}
		}

		void Bomb::collide(Entity* other, Math::CoordinateF intersection)
		{

			if (other->getID() == platform)
			{
				velocity.x *= 0.9;
				velocity.y *= 0.7;
			}
		}

		void Bomb::checkCollision(Entity* other, Math::CoordinateF intersection)
		{
		}

		

	}
}