#ifndef STATE_H
#define STATE_H

#include "GameState.h"

/**
 * States manage themselves. Are their own factory, creates other states, etc.
 * Abstract class.
 */

 class GameState;

class State {
    public:
        virtual void init()= 0;
        virtual void cleanUp() = 0;
        virtual void pause();
        virtual void resume();

        virtual void HandleEvents(GameState* game) = 0;
        virtual void Update(GameState* game) = 0;
        virtual void Draw(GameState* game) = 0;
};

#endif // STATE_H
