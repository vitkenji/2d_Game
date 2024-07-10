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
		~StaticEntity();

		void render();
		
		void update(const float dt){}

	};
}