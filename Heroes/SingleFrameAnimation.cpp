#include "SingleFrameAnimation.hpp"

namespace GraphicalElements
{
	SingleFrameAnimation::SingleFrameAnimation() : texture(nullptr) { }

	SingleFrameAnimation::~SingleFrameAnimation()
	{
		texture = nullptr;
	}

	void SingleFrameAnimation::initialize(const char* path, Math::CoordinateF position, Math::CoordinateF size)
	{
		texture = pGraphic->loadTexture(path);
		body.setPosition(sf::Vector2f(position.x, position.y));
		body.setSize(sf::Vector2f(size.x, size.y));
		body.setTexture(texture);
		body.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	}

	void SingleFrameAnimation::update(Math::CoordinateF position)
	{
		body.setPosition(sf::Vector2f(position.x, position.y));
	}
}