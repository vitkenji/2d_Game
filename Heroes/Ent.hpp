#pragma once
#include "std.h"

class Ent
{
protected:
	Math::CoordinateF position;
	Math::CoordinateF size;

public:
	Ent(Math::CoordinateF position, Math::CoordinateF size);
	virtual ~Ent();

	void setPosition(Math::CoordinateF position);
	void setSize(Math::CoordinateF size);
	Math::CoordinateF getPosition();
	Math::CoordinateF getSize();

	virtual void render() = 0;

};