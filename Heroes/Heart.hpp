#pragma once
#include "Animation.hpp"
#include "std.h"

namespace GraphicalElements
{
	enum HeartID
	{
		full = 0,
		half = 1,
		empty = 2
	};

	class Heart : public Animation
	{
	private:
		sf::Texture* fullTexture;
		sf::Texture* halfTexture;
		sf::Texture* emptyTexture;

	public:
		Heart();
		virtual ~Heart();

		void update(HeartID id, Math::CoordinateF position);

	};
}