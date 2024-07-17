#include "MenuControl.hpp"

namespace Control
{
	MenuControl::MenuControl(Menus::Menu* pMenu) : Observer(), pMenu(pMenu)
	{

	}

	MenuControl::~MenuControl()
	{
		this->pMenu = nullptr;
	}

	void MenuControl::notifyPressed(std::string key)
	{
		if (pMenu == nullptr)
		{
			std::cout << "error: pMenu is nullptr" << std::endl;
			exit(1);
		}
		
		if (key == "Down")
		{

		}
		if (key == "Up")
		{

		}
		if (key == "Enter")
		{

		}
		if (key == "Escape")
		{

		}
	}

	void MenuControl::notifyReleased(std::string key)
	{

	}

	void MenuControl::setMenu(Menus::Menu* pMenu)
	{
		this->pMenu = pMenu;
	}

}