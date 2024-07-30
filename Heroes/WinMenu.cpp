#include "WinMenu.hpp"

namespace Menus
{
	WinMenu::WinMenu(States::StateMachine* pStateMachine, States::Level* pLevel) : Menu(), States::State(pStateMachine, States::win), pLevel(pLevel), textControl(),
		title(Math::CoordinateF(0, 0), "YOU WON", FONT1_PATH), points(Math::CoordinateF(0,0), "", FONT1_PATH), nameLabel(Math::CoordinateF(0,0), "Name: ", FONT1_PATH),
		name(Math::CoordinateF(0,0), "", FONT1_PATH), pointsToIncrement(0)
	{	
		GraphicalElements::Button* button = nullptr;
		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y - 400), "PLAY AGAIN");
		button->select(true);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f , pGraphicManager->getWindowSize().y - 300), "MAIN MENU");
		buttons.push_back(button);
		
		title.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2, pGraphicManager->getWindowSize().y - 800));
		title.setFontSize(100);
		title.setTextAlignment(GraphicalElements::center);
		title.setTextColor(0,0,0);

		points.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2 - 400, pGraphicManager->getWindowSize().y - 700));
		points.setFontSize(35);
		points.setTextColor(0,0,0);
		points.setTextAlignment(GraphicalElements::center);

		nameLabel.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2 - 300, pGraphicManager->getWindowSize().y - 600));
		nameLabel.setFontSize(35);
		nameLabel.setTextColor(0,0,0);
		nameLabel.setTextAlignment(GraphicalElements::center);

		name.setPosition(Math::CoordinateF(nameLabel.getPosition().x + 100, nameLabel.getPosition().y - 30));
		name.setFontSize(35);
		name.setTextColor(0,0,0);
		name.setTextAlignment(GraphicalElements::center);

		selected = 0;
		max = 1;
	}

	WinMenu::~WinMenu()
	{

	}

	void WinMenu::update(const float dt)
	{
		active = true;
		name.setTextInfo(textControl.getString());
		if (pointsToIncrement < pLevel->getPlayerPoints())
			pointsToIncrement += 10;
		points.setTextInfo("Points: " + std::to_string(pLevel->getPlayerPoints()));
	}

	void WinMenu::render()
	{
		updateView();
		back.render();

		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->render();
		}

		title.render();
		points.render();
		name.render();
		nameLabel.render();

	}

	void WinMenu::resetState()
	{
		active = false;
		
		buttons[selected]->select(false);
		selected = 0;
		buttons[selected]->select(true);

		textControl.reset();
		
	}

	void WinMenu::saveInLeaderboard()
	{
		std::cout << "called save" << std::endl;
		unsigned int playerPoints = pLevel->getPlayerPoints();

		std::ifstream readFile;
		readFile.open(LEADERBOARD_PATH, std::ios::in);
		std::multimap<int, std::string> rankingMap;

		if (readFile)
		{
			unsigned int points;
			std::string name;
			std::string pointsString;

			for (int i = 0; i < 10; i++)
			{
				std::getline(readFile, pointsString);
				std::getline(readFile, name);
				if (pointsString.length() > 0)
				{
					rankingMap.insert(std::pair<int, std::string>(std::stoi(pointsString), name));
				}
			}
			readFile.close();

		}

		if (playerPoints != 0 && textControl.getString().length() > 1)
		{
			rankingMap.insert(std::pair<int, std::string>(playerPoints, textControl.getString()));
		}

		std::ofstream writeFile;

		writeFile.open(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);

		if (!writeFile)
		{
			std::cout << "error opening write file" << std::endl;
			exit(1);
		}

		while (rankingMap.size() > 10)
		{
			rankingMap.erase(rankingMap.begin());
		}

		for (auto it = rankingMap.rbegin(); it != rankingMap.rend(); it++)
		{
			writeFile << (*it).first << std::endl;
			writeFile << (*it).second << std::endl;
		}


		writeFile.close();
	}

	void WinMenu::execute()
	{
		if (active)
		{
			saveInLeaderboard();
			active = false;
			switch (selected)
			{
			case 0:
				changeState(States::playing);
				break;
			case 1:
				changeState(States::mainMenu);
				break;
			default:
				break;
			}

		}
		
	}

}