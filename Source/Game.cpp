#include "Game.h"
#include "States/State.h"

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
