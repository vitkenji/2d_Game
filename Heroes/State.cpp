#include "State.hpp"
#include "StateMachine.hpp"

namespace States
{
	State::State(StateMachine* pStateMachine, StateID id) : pStateMachine(pStateMachine), id(id)
	{

	}

	State::~State()
	{

	}

	void State::setStateMachine(StateMachine* pStateMachine)
	{
		this->pStateMachine = pStateMachine;
	}

	void State::changeState(StateID id)
	{
		pStateMachine->changeCurrentState(id);
	}

	StateID State::getStateID()
	{
		return id;
	}
}
