#include "Entity.hpp"

namespace Entities
{
	Entity::Entity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Ent(position, size), id(id), swordDistance(0), active(true)
	{

	}

	Entity::~Entity()
	{

	}

	float Entity::getSwordDistance()
	{
		return this->swordDistance;
	}

	void Entity::setID(ID id)
	{
		this->id = id;
	}

	ID Entity::getID() const
	{
		return this->id;
	}

	void Entity::setActive(bool active)
	{
		this->active = active;
	}


	bool Entity::isActive()
	{
		return active;
	}

}