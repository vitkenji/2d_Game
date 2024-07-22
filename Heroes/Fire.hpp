#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Obstacles
	{
		class Fire : public MovingEntity
		{
		private:

		public:
			Fire(Math::CoordinateF position);
			virtual ~Fire();

			void addAnimations();

			void update(const float dt);
			void collide(Entity* other, Math::CoordinateF intersection);
			void updateSprite(const float dt);
			void checkCollision(Entity* other, Math::CoordinateF insersection);

		};
	}
}