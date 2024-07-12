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
			updateSprite(dt);
		}

		void Bomb::updateSprite(const float dt)
		{
			sprite.update(GraphicalElements::explode, isFacingRight(), this->position, dt);
		}

		void Bomb::collide(Entity* other, Math::CoordinateF intersection)
		{

		}



	}
}