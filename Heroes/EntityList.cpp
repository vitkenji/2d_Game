#include "EntityList.hpp"

namespace List
{
	EntityList::EntityList() : entitiesList()
	{

	}

	EntityList::~EntityList()
	{
		

	}

	void EntityList::addEntity(Entities::Entity* pEntity)
	{
		entitiesList.push(pEntity);

	}

	Entities::Entity* EntityList::removeEntity(Entities::Entity* pEntity)
	{
		return entitiesList.pop(pEntity);

	}

	Entities::Entity* EntityList::removeEntity(unsigned int index)
	{
		return entitiesList.pop(index);

	}

	void EntityList::deleteEntity(Entities::Entity* pEntity)
	{
		Entities::Entity* ptr = nullptr;
		ptr = entitiesList.pop(pEntity);
		if (ptr) { delete ptr; }

	}

	void EntityList::deleteEntity(unsigned int index)
	{
		Entities::Entity* ptr = nullptr;
		ptr = entitiesList.pop(index);
		if (ptr) { delete ptr; }

	}

	unsigned int EntityList::getSize()
	{
		return entitiesList.getSize();

	}

	Entities::Entity* EntityList::operator[](int index)
	{
		return entitiesList[index];
	}

	void EntityList::clearList()
	{
		entitiesList.clear();

	}




}
