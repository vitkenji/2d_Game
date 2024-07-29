#include "TextControl.hpp"

namespace Control
{
	TextControl::TextControl() : Observer()
	{

	}

	TextControl::~TextControl()
	{

	}

	void TextControl::notifyPressed(std::string key)
	{
		if (key == "Enter" ||
			key == "Right" ||
			key == "Left" ||
			key == "Up" ||
			key == "Down" ||
			key == "Escape" ||
			key == "Control" ||
			key == "Shift" ||
			key == "RControl" ||
			key == "RShift" ||
			key == "Tab" ||
			key == "Unknown") {
			return;
		}
		else if (key == "Space")
		{
			text += " ";
		}
		else if (key == "BackSpace")
		{
			if (text.size() > 0)
			{
				text.pop_back();
			}
		}
		else
		{
			text += key;
		}
	}

	void TextControl::notifyReleased(std::string key)
	{

	}

	std::string TextControl::getString()
	{
		return text;
	}

	void TextControl::reset()
	{
		text = "";
	}
}