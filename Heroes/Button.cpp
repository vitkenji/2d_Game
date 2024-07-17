#include "Button.hpp"

namespace GraphicalElements
{

	Button::Button(Math::CoordinateF position, std::string info) : textInfo(position, info), defaultTexture(nullptr), selectedTexture(nullptr)
	{
		defaultTexture = pGraphic->loadTexture(DEFAULT_BUTTON_PATH);
		selectedTexture = pGraphic->loadTexture(SELECTED_BUTTON_PATH);
		body.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
		body.setOrigin(sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2));
		body.setPosition(position.x, position.y);
		body.setTexture(defaultTexture);
		textInfo.setFontSize(FONT_SIZE);
		textInfo.setTextAlignment(TextAlignment::center);
		textInfo.setTextColor(BUTTON_TEXT_COLOR);
		textInfo.setPosition(position);

	}

	Button::~Button()
	{

	}

	void Button::select(bool selected)
	{
		if (selected)
		{
			body.setTexture(selectedTexture);
			body.setFillColor(sf::Color(255, 255, 255));
			
		}
		else
		{
			body.setTexture(defaultTexture);
			body.setFillColor(sf::Color(150, 150, 150));
			
		}
	}

	void Button::render()
	{
		pGraphic->render(&body);
		textInfo.render();
	}

	void Button::lowerTextPosition()
	{
		textInfo.setPosition(Math::CoordinateF(textInfo.getPosition().x, textInfo.getPosition().y + 8));
	}

	void Button::raiseTextPosition()
	{
		textInfo.setPosition(Math::CoordinateF(textInfo.getPosition().x, textInfo.getPosition().y - 8));
	}
}