#include "Entity.hpp"

namespace Entities
{
	Entity::Entity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Ent(position, size), id(id)
	{

	}

	Entity::~Entity()
	{

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