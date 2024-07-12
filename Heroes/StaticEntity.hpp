#pragma once
#include "Entity.hpp"
#include "SingleFrameAnimation.hpp"

namespace Entities
{
	class StaticEntity : public Entity
	{
	protected:
		GraphicalElements::SingleFrameAnimation sprite;

	public:
		StaticEntity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		virtual ~StaticEntity();

		void render();
		virtual void update(const float dt){}
		void collide(Entity* other, Math::CoordinateF intersection);

	};
}