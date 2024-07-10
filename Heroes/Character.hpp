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


		public:
			Character(Math::CoordinateF position, Math::CoordinateF size, ID id);
			~Character();

			void restartSprite(const float dt, float animationTime);
			virtual void update(const float dt) = 0;
		};
	}
}