#pragma once
#include "Animation.hpp"
#include "GraphicManager.hpp"
#include "std.h"

namespace GraphicalElements
{
	enum TextAlignment
	{
		left,
		center,
		right
	};

	class Text
	{
	private:
		std::string info;
		sf::Text text;
		static Managers::GraphicManager* pGraphicManager;

	public:
		Text(Math::CoordinateF position, std::string info, const char* path);
		~Text();

		void setTextInfo(std::string info);
		void setPosition(Math::CoordinateF position);
		void setTextColor(int r, int g, int b);
		void setFontSize(const int size);
		void setTextAlignment(TextAlignment aligment);
		void render();
		int getStringLength();
		Math::CoordinateF getSize();
		std::string getInfo();
		Math::CoordinateF getPosition();

	};
}