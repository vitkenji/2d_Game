#include "StateMachine.hpp"

namespace States
{
	StateMachine::StateMachine() : statesMap()
	{
		currentStateID = unknown;
		lastStateID = unknown;
	}

	StateMachine::~StateMachine()
	{
		std::map<StateID, State*>::iterator i;
		for (i = statesMap.begin(); i != statesMap.end(); i++)
		{
			delete(i->second);
		}
	}

	void StateMachine::changeCurrentState(StateID id)
	{
		std::cout << "changed to" << id  << std::endl;
		lastStateID = currentStateID;
		currentStateID = id;
		statesMap[currentStateID]->resetState();
	}

	void StateMachine::updateCurrentState(const float dt)
	{
		statesMap[currentStateID]->update(dt);
	}

	void StateMachine::renderCurrentState()
	{
		statesMap[currentStateID]->render();

	}

	void StateMachine::insertState(State* pState)
	{
		if (pState == nullptr)
		{
			std::cout << "error pointer to State NULL on StateMachine::insertState()" << std::endl;
			exit(1);
		}
		statesMap.insert(std::pair<StateID, State*>(pState->getStateID(), pState));
	}

	StateID StateMachine::getCurrentStateID()
	{
		return currentStateID;
	}
	
	StateID StateMachine::geLastStateID()
	{
		return lastStateID;
	}

}