#include "Character.hpp"

namespace Entities
{
	namespace Characters
	{
		Character::Character(Math::CoordinateF position, Math::CoordinateF size, ID id) : MovingEntity(position, size, id), 
			isWalking(false), isAttacking(false), isTakingHit(false), cooldown(0), life(10000)
		{
			acceleration = Math::CoordinateF(0, GRAVITY);
		}

		Character::~Character()
		{
		}

		void Character::setIsAttacking(bool isAttacking)
		{
			this->isAttacking = isAttacking;
		}

		bool Character::getIsAttacking()
		{
			return this->isAttacking;
		}

		void Character::restartSprite(const float dt, float animationTime)
		{

		}

		void Character::takeDamage(float damage)
		{
			this->life -= damage;

		}

		int Character::getDamage()
		{
			return this->damage;
		}

	}
}