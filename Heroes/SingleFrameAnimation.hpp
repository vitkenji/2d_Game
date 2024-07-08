#pragma once
#include "Animation.hpp"

namespace GraphicalElements
{
	class SingleFrameAnimation : public Animation
	{
	private:
		sf::Texture* texture;

	public:
		SingleFrameAnimation();
		~SingleFrameAnimation();
		void initialize(const char* path, Math::CoordinateF position, Math::CoordinateF size);
		void update(Math::CoordinateF position);

	};
}