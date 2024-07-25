#include "StateMachine.hpp"

namespace States
{
	StateMachine::StateMachine() : statesMap()
	{
		currentStateID = States::unknown;
		lastStateID = States::unknown;
	}

	StateMachine::~StateMachine()
	{
		std::map<States::StateID, State*>::iterator i;
		for (i = statesMap.begin(); i != statesMap.end(); i++)
		{
			delete(i->second);
		}
	}

	void StateMachine::changeCurrentState(States::StateID id)
	{
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

	void StateMachine::insertState(States::State* pState)
	{
		if (pState == nullptr)
		{
			std::cout << "error pointer to State NULL on StateMachine::insertState()" << std::endl;
			exit(1);
		}
		statesMap.insert(std::pair<StateID, States::State*>(pState->getStateID(), pState));
	}

	States::StateID StateMachine::getCurrentStateID()
	{
		return currentStateID;
	}
	
	States::StateID StateMachine::geLastStateID()
	{
		return lastStateID;
	}

}