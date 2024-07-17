#include "Text.hpp"

namespace GraphicalElements
{
	Managers::GraphicManager* Text::pGraphicManager = Managers::GraphicManager::getInstance();

	Text::Text(Math::CoordinateF position, std::string info, const char* path)
	{
		text.setString(info);
		text.setFont(*pGraphicManager->loadFont(path));
		text.setPosition(sf::Vector2f(position.x, position.y));
		text.setCharacterSize(FONT_SIZE);
		text.setFillColor(sf::Color::White);
		setTextAlignment(TextAlignment::left);

	}

	Text::Text()
	{

	}

	Text::~Text()
	{

	}

	void Text::setTextInfo(std::string info)
	{
		this->info = info;
		text.setString(info);
	}

	void Text::setPosition(Math::CoordinateF position)
	{
		text.setPosition(sf::Vector2f(position.x, position.y));
	}

	void Text::setTextColor(int r, int g, int b)
	{
		text.setFillColor(sf::Color(r, g, b));
	}

	void Text::setTextAlignment(TextAlignment alignment)
	{
		switch (alignment)
		{
		case TextAlignment::left:
			text.setOrigin(0, 0);
		case TextAlignment::center:
			text.setOrigin(getSize().x / 2, getSize().y);
			break;
		case TextAlignment::right:
			text.setOrigin(getSize().x, 0);
			break;
		default: 
			text.setOrigin(getSize().x / 2, getSize().y);
			break;
		}
	}

	void Text::setFontSize(const int size)
	{
		text.setCharacterSize(size);
	}

	void Text::render()
	{
		pGraphicManager->render(&text);
	}

	Math::CoordinateF Text::getSize()
	{
		sf::FloatRect textRect = text.getLocalBounds();
		return Math::CoordinateF(textRect.width, textRect.height);
	}

	std::string Text::getInfo()
	{
		return info;
	}

	Math::CoordinateF Text::getPosition()
	{
		return Math::CoordinateF(text.getPosition().x, text.getPosition().y);
	}
}