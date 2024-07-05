#include <SFML/Graphics.hpp>
#include "GraphicManager.hpp"

int main()
{
    Managers::GraphicManager* pGraphic = Managers::GraphicManager::getInstance();

    while (pGraphic->isWindowOpen())
    {
        sf::Event event;
        while (pGraphic->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGraphic->closeWindow();
        }

        pGraphic->display();
        pGraphic->clear();
    }

    return 0;
}