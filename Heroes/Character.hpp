#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Characters
	{
		class Character : public MovingEntity
		{
		protected:
			int life;
			int damage;
			bool isTakingHit;
			bool isWalking;
			bool isAttacking;

			float cooldown;

		public:
			Character(Math::CoordinateF position, Math::CoordinateF size, ID id);
			virtual ~Character();

			void setIsAttacking(bool isAttacking);
			bool getIsAttacking();

			void takeDamage(float damage);
			int getDamage();

			void manageTakeHitCooldown(const float dt);

			virtual void update(const float dt) = 0;
			virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
			virtual void checkCollision(Entity* other, Math::CoordinateF insersection) = 0;
			
		};
	}
}