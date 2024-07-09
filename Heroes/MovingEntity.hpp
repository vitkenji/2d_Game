#pragma once
#include "Entity.hpp"
#include "MultiFrameAnimation.hpp"
#include "paths.h"

namespace Entities
{
	class MovingEntity : public Entity
	{
	public:
		GraphicalElements::MultiFrameAnimation sprite;
		Math::CoordinateF velocity;
		Math::CoordinateF acceleration;

	public:
		MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		~MovingEntity();
		void render();
	};
}