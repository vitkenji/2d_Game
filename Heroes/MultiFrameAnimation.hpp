#pragma once
#include "Animation.hpp"
#include "SingleAnimation.hpp"

namespace GraphicalElements
{
	enum Animation_ID
	{
		walk = 0,
		idle,
		attack,
		run,
		cooldown,
		jump,
		takeHit,
		death,
		fall

	};

	class MultiFrameAnimation : public Animation
	{
	private:
		std::map<Animation_ID, SingleAnimation*> animationMap;
		Animation_ID currentID;

	public:
		MultiFrameAnimation();
		~MultiFrameAnimation();
		void addNewAnimation(Animation_ID ID, const char* path, const unsigned int imageCount, float switchTime);
		void update(Animation_ID ID, bool facingLeft, Math::CoordinateF position, const float dt);

	};
}