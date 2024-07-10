#pragma once
#include "Entity.hpp"
#include "MultiFrameAnimation.hpp"

namespace Entities
{
	class MovingEntity : public Entity
	{
	protected:
		GraphicalElements::MultiFrameAnimation sprite;
		Math::CoordinateF velocity;
		Math::CoordinateF acceleration;
		bool facingRight;

	public:
		MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		~MovingEntity();
		void setFacingRight(bool right);
		bool isFacingRight();
		void render();

		virtual void update(const float dt) = 0;
		virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;

	};
}