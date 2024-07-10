#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.hpp"

namespace Entities
{
	enum ID {
		player = 0,
		platform,
		skeleton,
		goblin
	};

	class Entity : public Ent
	{
	protected:
		ID id;

	public:
		Entity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		Entity();
		~Entity();

		void setID(ID id);
		ID getID() const;

		virtual void render() = 0;
		virtual void update(const float dt) = 0;

	};
}