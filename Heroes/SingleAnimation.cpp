#include "SingleAnimation.hpp"

namespace GraphicalElements
{
	SingleAnimation::SingleAnimation(const char* path, const unsigned int imageCount, const float switchTime) :
		imageCount(imageCount), currentImage(0), texture(Managers::GraphicManager::getInstance()->loadTexture(path)), totalTime(0), rectangleSize(), switchTime(switchTime)
	{
		if (texture == nullptr)
		{
			std::cout << "Error loading font" << std::endl;
			exit(1);
		}
		rectangleSize.width = texture->getSize().x / (float)imageCount;
		rectangleSize.height = texture->getSize().y;

	}

	SingleAnimation::~SingleAnimation()
	{
		texture = nullptr;

	}

	void SingleAnimation::update(float dt, bool facingRight)
	{
		totalTime += dt;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			currentImage++;
			if (currentImage >= imageCount)
			{
				currentImage = 0;
			}
		}

		if (!facingRight)
		{
			rectangleSize.left = (currentImage + 1) * abs(rectangleSize.width);
			rectangleSize.width = -abs(rectangleSize.width);

		}
		else
		{
			rectangleSize.left = currentImage * abs(rectangleSize.width);
			rectangleSize.width = abs(rectangleSize.width);
		}

	}

	void SingleAnimation::reset()
	{
		currentImage = 0;
		totalTime = 0;

	}

	sf::IntRect SingleAnimation::getRectangleSize() const
	{
		return rectangleSize;

	}

	sf::Texture* SingleAnimation::getTexture() const
	{
		return texture;

	}


}