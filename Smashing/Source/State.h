#pragma once
#include "Game.h"

class State
{
public:
    virtual void enter() = 0;
    virtual void update() = 0;
    virtual void exit() = 0;
};
