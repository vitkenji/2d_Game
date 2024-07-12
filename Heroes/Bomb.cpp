#include "Bomb.hpp"

namespace Entities
{
	namespace Projectiles
	{
		Bomb::Bomb(Math::CoordinateF position) : Projectile(position, Math::CoordinateF(BOMB_SIZE_X, BOMB_SIZE_Y), bomb)
		{
			addAnimations();
		}

		Bomb::~Bomb()
		{

		}

		void Bomb::addAnimations()
		{
			sprite.addNewAnimation(GraphicalElements::explode, BOMB_PATH, 19, 1);
		}

		void Bomb::update(const float dt)
		{
			position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
			velocity.y += acceleration.y * dt;
			updateSprite(dt);
		}

		void Bomb::updateSprite(const float dt)
		{
			sprite.update(GraphicalElements::explode, isFacingRight(), this->position, dt);
		}

		void Bomb::collide(Entity* other, Math::CoordinateF intersection)
		{

			if (other->getID() == platform)
			{
				velocity.y /= -1.21;
			}
		}

		void Bomb::checkCollision(Entity* other, Math::CoordinateF intersection)
		{
		}



	}
}