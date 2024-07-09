#include "Character.hpp"

namespace Entities
{
	namespace Characters
	{
		Character::Character(Math::CoordinateF position, Math::CoordinateF size, ID id) : MovingEntity(position, size, id)
		{

		}

		Character::~Character()
		{
		}

		void Character::restartSprite(const float dt, float animationTime)
		{

		}

	}
}