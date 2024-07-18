#include "MainMenu.hpp"
#include "Game.hpp"

namespace Menus
{
	Managers::GraphicManager* pG = Managers::GraphicManager::getInstance();

	MainMenu::MainMenu(States::Game* pGame) : Menu(), States::State(static_cast<States::StateMachine*>(pGame), States::StateID::mainMenu), pGame(pGame),
		title(Math::CoordinateF(300, 300), "HEROES", FONT2_PATH)
	{

		GraphicalElements::Button* button = nullptr;
		button = new GraphicalElements::Button(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 ), "PLAY");
		button->select(true);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 + 100), "SETTINGS");
		button->select(false);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 + 200), "LEADERBOARD");
		button->select(false);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 + 300), "QUIT");
		button->select(false);
		buttons.push_back(button);

		title.setFontSize(160);
		title.setTextInfo("HEROES");
		title.setTextColor(0,0,0);
		title.setTextAlignment(GraphicalElements::TextAlignment::center);
		title.setPosition(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 - 200));

		min = 0;
		max = 3;

	}

	MainMenu::~MainMenu()
	{

	}

	void MainMenu::update(const float dt)
	{
		active = true;



	}
	void MainMenu::render()
	{
		updateView();
		back.render();
		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->render();
		}
		
		title.render();
	}
	void MainMenu::resetState()
	{
		
	}
	void MainMenu::execute()
	{
		if (active) {
			active = false;
			switch (selected) {
			case 0:
				changeState(States::StateID::playing);
				break;
			case 1:
				changeState(States::StateID::leaderboard);
				break;
			case 2:
				changeState(States::StateID::settings);
				break;
			case 3:
				pGame->quit();
				break;
			default:
				break;
			}
		}
	}
}