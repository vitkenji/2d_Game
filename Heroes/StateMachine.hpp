#pragma once
#include "State.hpp"
#include <map>
#include <iostream>

namespace States
{
	class StateMachine
	{
	protected:
		StateID currentStateID;
		StateID lastStateID;
		std::map<StateID, State*> statesMap;

	public:
		StateMachine();
		virtual ~StateMachine();

		void changeCurrentState(StateID id);
		void updateCurrentState(const float dt);
		void renderCurrentState();
		StateID getCurrentStateID();
		void insertState(State* pState);
		StateID geLastStateID();

	};
}