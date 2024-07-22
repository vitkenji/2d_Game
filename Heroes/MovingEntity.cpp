#include "MovingEntity.hpp"

namespace Entities
{
	MovingEntity::MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Entity(position, size, id),
		sprite(), velocity(Math::CoordinateF(0,0)), acceleration(0, GRAVITY)
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

	void MovingEntity::setVelocity(Math::CoordinateF velocity)
	{
		this->velocity = velocity;
	}

	Math::CoordinateF MovingEntity::getVelocity()
	{
		return this->velocity;
	}

	void MovingEntity::fallToGravity(const float dt)
	{
		position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
		velocity.y += acceleration.y * dt;
	}

	void MovingEntity::setDamage(int damage)
	{
		this->damage = damage;
	}

	int MovingEntity::getDamage()
	{
		return this->damage;
	}

}