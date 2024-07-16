#pragma once
#include "Ent.hpp"

Ent::Ent(Math::CoordinateF position, Math::CoordinateF size)
{
	this->position = position;
	this->size = size;
}

Ent::~Ent() {}

void Ent::setPosition(Math::CoordinateF position)
{
	this->position = position;
}

void Ent::setSize(Math::CoordinateF size)
{
	this->size = size;
}

Math::CoordinateF Ent::getPosition()
{
	return this->position;
}

Math::CoordinateF Ent::getSize()
{
	return this->size;
}