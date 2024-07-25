#include "EntityList.hpp"

namespace List
{
	EntityList::EntityList() : entitiesList()
	{

	}

	EntityList::~EntityList()
	{
		entitiesList.clear();

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
		Entities::Entity* tmp = nullptr;

		tmp = entitiesList.pop(pEntity);

	}

	void EntityList::deleteEntity(unsigned int index)
	{
		
		Entities::Entity* ptr = nullptr;
		ptr = entitiesList.pop(index);
		if (ptr == nullptr)
		{
			std::cout << "Error: ptr is nullptr" << std::endl;
		}
		if (ptr)
		{
			std::cout << ptr->getID() << " deleted" << std::endl;
			delete ptr; 
		}

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
