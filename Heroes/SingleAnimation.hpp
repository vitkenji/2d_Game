#pragma once
#include "GraphicManager.hpp"

namespace GraphicalElements
{
	class SingleAnimation
	{
	private:
		const unsigned int imageCount;
		unsigned int currentImage;
		sf::Texture* texture;
		float totalTime;
		sf::IntRect rectangleSize;
		const float switchTime;

	public:
		SingleAnimation(const char* path, const unsigned int imageCount, const float switchTime);
		~SingleAnimation();
		void update(float dt, bool facingLeft);
		void reset();
		sf::IntRect getRectangleSize() const;
		sf::Texture* getTexture() const;

	};
}