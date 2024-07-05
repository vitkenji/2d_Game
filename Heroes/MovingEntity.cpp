#include "MovingEntity.hpp"

namespace Entities
{
	MovingEntity::MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Entity(position, size, id), sprite()
	{
		sprite.addNewAnimation(GraphicalElements::idle, PLAYER_IDLE_PATH, 8, 0.8);
	}
}