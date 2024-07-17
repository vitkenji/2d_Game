#pragma once
#include <vector>
#include "Button.hpp"
#include "MenuControl.hpp"
#include "SingleFrameAnimation.hpp"

namespace Menus
{
	class Menu
	{
	protected:
		std::vector<GraphicalElements::Button*> buttons;
		std::vector<GraphicalElements::Button*>::iterator i;
		int selected;
		int min;
		int max;
		Control::MenuControl menuControl;
		bool active;
		GraphicalElements::SingleFrameAnimation back;

	public:
		Menu();
		virtual ~Menu();
		virtual void execute() = 0;
		void updateView();
		void selectDown();
		void selectUp();

	};
}