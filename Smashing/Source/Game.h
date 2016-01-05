#pragma once
#include "State.h"

class Game
{
    State &currentState;

public:
    Game(State &initialState);

    void changeState(State &newState);
    State &getCurrentState();
    void update();
};