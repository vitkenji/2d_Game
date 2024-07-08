#include "MovingEntity.hpp"

namespace Entities
{
	MovingEntity::MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Entity(position, size, id), sprite()
	{

	}

	MovingEntity::~MovingEntity(){}
}