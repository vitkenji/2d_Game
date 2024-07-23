#include "Heart.hpp"

namespace GraphicalElements
{
	Heart::Heart() : Animation()
	{
		fullTexture = pGraphic->loadTexture(FULL_HEART_PATH);
		halfTexture = pGraphic->loadTexture(HALF_HEART_PATH);
		emptyTexture = pGraphic->loadTexture(EMPTY_HEART_PATH);

		body.setTexture(fullTexture);
		body.setOrigin(0,0);
		body.setSize(sf::Vector2f(HEART_SIZE_X, HEART_SIZE_Y));
	}

	Heart::~Heart()
	{

	}

	void Heart::update(HeartID id, Math::CoordinateF position)
	{
		body.setPosition(sf::Vector2f(position.x, position.y));
		switch (id)
		{
		case full:
			body.setTexture(fullTexture);
			break;
		case half:
			body.setTexture(halfTexture);
			break;
		case empty:
			body.setTexture(emptyTexture);
			break;
		}
	}
}