#pragma once
#include "Observer.hpp"

namespace Control
{
	class TextControl : public Observer
	{
	private:
		std::string text;

	public:
		TextControl();
		~TextControl();
		void notifyPressed(std::string key);
		void notifyReleased(std::string key);
		std::string getString();
		void reset();

	};
}