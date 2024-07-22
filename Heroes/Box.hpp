#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Obstacles
	{
		class Box : public MovingEntity
		{
		private:
		public:
			Box(Math::CoordinateF intersection);
			~Box();
			void update(const float dt);
			void updateSprite(const float dt);
			
			void collide(Entity* other, Math::CoordinateF intersection);
			void checkCollision(Entity* other, Math::CoordinateF intersection);
			void addAnimations();
		};
	}
}