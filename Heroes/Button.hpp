#pragma once
#include "Animation.hpp"
#include "Coordinate.hpp"
#include "Text.hpp"

namespace GraphicalElements
{
	class Button : public Animation
	{
	private:
		Text textInfo;
		sf::Texture* defaultTexture;
		sf::Texture* selectedTexture;

	public:
		Button(Math::CoordinateF position, std::string info);
		~Button();
		void select(bool selected);
		void render();

	};
}