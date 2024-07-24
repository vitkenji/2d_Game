#include "Character.hpp"

namespace Entities
{
	namespace Characters
	{
		Character::Character(Math::CoordinateF position, Math::CoordinateF size, ID id) : MovingEntity(position, size, id), 
			isWalking(false), isAttacking(false), isTakingHit(false), cooldown(0), life(10000)
		{
			
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

		void Character::manageTakeHitCooldown(const float dt)
		{
			if (isTakingHit == true)
			{
				cooldown += dt;
				if (cooldown >= 2)
				{
					cooldown = 0;
					isTakingHit = false;

				}
			}
		}

		void Character::takeDamage(float damage)
		{
			this->life -= damage;

		}

		int Character::getDamage()
		{
			return this->damage;
		}

		int Character::getLife()
		{
			return this->life;
		}

	}
}