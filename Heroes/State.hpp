#pragma once

namespace States
{
	class StateMachine;

	enum StateID
	{
		unknown = -1,
		mainMenu = 0,
		newGame,
		playing,
		pauseMenu,
		settings,
		leaderboard,
		gameOver
	};

	class State
	{
	protected:
		StateMachine* pStateMachine;
		StateID id;

	public:
		State(StateMachine* pStateMachine, StateID id);
		virtual ~State();

		void setStateMachine(StateMachine* pStateMachine);
		void changeState(StateID id);
		StateID getStateID();

		virtual void update(const float dt) = 0;
		virtual void render() = 0;
		virtual void resetState() = 0;

	};
}