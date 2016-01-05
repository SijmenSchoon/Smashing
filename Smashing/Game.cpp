#include "Game.h"

Game::Game(State &initialState)
	: currentState(initialState)
{
	initialState.enter();
}

void Game::changeState(State &newState)
{
	currentState.exit();
	currentState = newState;
	currentState.enter();
}

State &Game::getCurrentState()
{
	return currentState;
}

void Game::update()
{
	currentState.update();
}
