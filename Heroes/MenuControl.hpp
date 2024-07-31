#pragma once
#include "Observer.hpp"

namespace Menus
{
	class Menu;
}

namespace Control
{
	class MenuControl : public Observer
	{
	private:
		Menus::Menu* pMenu;

	public:
		MenuControl(Menus::Menu* pMenu);
		~MenuControl();

		void notifyPressed(std::string key);
		void notifyReleased(std::string key);
		void setMenu(Menus::Menu* pMenu);
	};
}