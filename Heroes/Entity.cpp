#include "Entity.hpp"

namespace Entities
{
	Entity::Entity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Ent(position, size), id(id), swordDistance(0)
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

}