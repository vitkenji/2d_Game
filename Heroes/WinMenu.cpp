#include "WinMenu.hpp"

namespace Menus
{
	WinMenu::WinMenu(States::StateMachine* pStateMachine, States::Level* pLevel) : Menu(), States::State(pStateMachine, States::win), pLevel(pLevel), textControl(),
		title(Math::CoordinateF(0, 0), "YOU WON", FONT1_PATH), points(Math::CoordinateF(0,0), "", FONT1_PATH), nameLabel(Math::CoordinateF(0,0), "Name: ", FONT1_PATH),
		name(Math::CoordinateF(0,0), "", FONT1_PATH), pointsToIncrement(0)
	{	
		GraphicalElements::Button* button = nullptr;
		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f - 200, pGraphicManager->getWindowSize().y - 100), "PLAY AGAIN");
		button->select(true);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f + 200, pGraphicManager->getWindowSize().y - 100), "MAIN MENU");
		buttons.push_back(button);
		
		title.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2, pGraphicManager->getWindowSize().y - 200));
		title.setFontSize(100);
		title.setTextAlignment(GraphicalElements::center);
		title.setTextColor(77.6, 68.2, 44.3);

		points.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2 - 100, pGraphicManager->getWindowSize().y));
		points.setFontSize(40);
		points.setTextColor(77.6, 68.2, 44.3);
		points.setTextAlignment(GraphicalElements::center);

		nameLabel.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2 - 200, pGraphicManager->getWindowSize().y + 100));
		nameLabel.setFontSize(40);
		nameLabel.setTextColor(77.6, 68.2, 44.3);
		nameLabel.setTextAlignment(GraphicalElements::center);

		name.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2 - 300, pGraphicManager->getWindowSize().y + 200));
		name.setFontSize(40);
		name.setTextColor(77.6, 68.2, 44.3);
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
		buttons[selected]->select(false);
		
	}

	void WinMenu::saveInLeaderboard()
	{
		unsigned int playerPoints;

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

		for (auto it = rankingMap.begin(); it != rankingMap.end(); it++)
		{
			writeFile << (*it).first << std::endl;
			writeFile << (*it).second << std::endl;
		}


		writeFile.close();
	}

	void WinMenu::execute()
	{

	}

}