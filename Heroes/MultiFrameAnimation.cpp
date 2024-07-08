#include "MultiFrameAnimation.hpp"

namespace GraphicalElements
{
	MultiFrameAnimation::MultiFrameAnimation() : Animation(), animationMap(), currentID(Animation_ID::idle)
	{

	}

	MultiFrameAnimation::~MultiFrameAnimation()
	{
		std::map<Animation_ID, SingleAnimation*>::iterator i;
		for (i = animationMap.begin(); i != animationMap.end(); i++)
		{
			delete(i->second);
		}
		animationMap.clear();

	}

	void MultiFrameAnimation::addNewAnimation(Animation_ID ID, const char* path, const unsigned int imageCount, float switchTime)
	{
		SingleAnimation* animation = new SingleAnimation(path, imageCount, switchTime);
		if (animation == nullptr)
		{
			std::cout << "Error : singleAnimation is nullptr" << std::endl;
			exit(1);
		}

		animationMap.insert(std::pair<Animation_ID, SingleAnimation*>(ID, animation));
		sf::IntRect rectangleSize = animation->getRectangleSize();
		body.setSize(sf::Vector2f(rectangleSize.width, rectangleSize.height));
		body.setOrigin(sf::Vector2f(rectangleSize.width, rectangleSize.height) / 2.0f);

	}

	void MultiFrameAnimation::update(Animation_ID ID, bool facingRight, Math::CoordinateF position, const float dt)
	{
		if (currentID != ID)
		{
			currentID = ID;
			animationMap[currentID]->reset();
		}
		animationMap[currentID]->update(dt, facingRight);
		body.setPosition(sf::Vector2f(position.x, position.y));
		body.setTextureRect(animationMap[currentID]->getRectangleSize());
		body.setTexture(animationMap[currentID]->getTexture());

	}

}
