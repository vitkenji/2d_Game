#pragma once
#include "List.hpp"
#include "Entity.hpp"

namespace List
{
	class EntityList
	{
	private:
		List<Entities::Entity> entitiesList;

	public:
		EntityList();
		~EntityList();
		void addEntity(Entities::Entity* pEntity);
		Entities::Entity* removeEntity(Entities::Entity* pEntity);
		Entities::Entity* removeEntity(unsigned int index);
		void deleteEntity(Entities::Entity* pEntity);
		void deleteEntity(unsigned int index);
		unsigned int getSize();
		Entities::Entity* operator[](int index);
		void clearList();

	};
}