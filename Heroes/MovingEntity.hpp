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
		virtual ~MovingEntity();

		void setFacingRight(bool right);
		bool isFacingRight();
		virtual void render();

		void setVelocity(Math::CoordinateF velocity);
		Math::CoordinateF getVelocity();

		void fallToGravity(const float dt);

		virtual void update(const float dt) = 0;
		virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
		virtual void checkCollision(Entity* other, Math::CoordinateF insersection) = 0;

	};
}