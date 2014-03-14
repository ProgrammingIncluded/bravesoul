#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <stdio.h>
#include <vector>
#include <memory>
#include <stack>
#include "State.h"

/// manages stack empty error, state errors

class State;

class GameState
{
    public:
        GameState(); // constructor starts off with a state
        virtual ~GameState();
        void display(); // runs the first state on the stack

    private:
        std::stack<State*> s;
};

#endif // GAMESTATE_H
