#pragma once

class State;

class StateManager
{
protected:
    State &currentState;

public:
    StateManager(State &initialState) : currentState(initialState) { };

    virtual void changeState(State &newState)=0;
    virtual State &getCurrentState()=0;
    virtual void update()=0;
};
