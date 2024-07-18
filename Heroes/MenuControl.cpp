#include "MenuControl.hpp"
#include "Menu.hpp"
#include <iostream>

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
			pMenu->selectDown();
		}
		if (key == "Up")
		{
			pMenu->selectUp();
		}
		if (key == "Enter")
		{
			pMenu->execute();
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