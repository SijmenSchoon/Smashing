#pragma once
#include "State.h"

class GameState : public State
{
public:
    void enter();
    void update();
    void exit();
};