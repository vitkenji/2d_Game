#include "MovingEntity.hpp"

namespace Entities
{
	MovingEntity::MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Entity(position, size, id),
		sprite(), velocity(Math::CoordinateF(0,0)), acceleration(0, 0)
	{

	}

	MovingEntity::~MovingEntity(){}

	void MovingEntity::render()
	{
		sprite.render();
	}

	void MovingEntity::setFacingRight(bool right)
	{
		facingRight = right;
	}

	bool MovingEntity::isFacingRight()
	{
		return facingRight;
	}

	bool MovingEntity::isActive()
	{
		return active;
	}

	void MovingEntity::setVelocity(Math::CoordinateF velocity)
	{
		this->velocity = velocity;
	}

	Math::CoordinateF MovingEntity::getVelocity()
	{
		return this->velocity;
	}

}