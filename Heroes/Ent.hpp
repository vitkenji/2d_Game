#pragma once
#include "Coordinate.hpp"
#include "constants.h"
#include "paths.h"


class Ent
{
protected:
	Math::CoordinateF position;
	Math::CoordinateF size;

public:
	Ent(Math::CoordinateF position, Math::CoordinateF size);
	Ent();
	~Ent();
	void setPosition(Math::CoordinateF position);
	void setSize(Math::CoordinateF size);
	Math::CoordinateF getPosition();
	Math::CoordinateF getSize();

};