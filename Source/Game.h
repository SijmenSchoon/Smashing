#pragma once
#include "StateManager.h"

class Game : public StateManager
{
public:
    void changeState(State &newState);
    State &getCurrentState();
    void update();
};
