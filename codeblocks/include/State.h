#ifndef STATE_H
#define STATE_H

#include "Game.h"

/**
 * States manage themselves. Are their own factory, creates other states, etc.
 * Abstract class.
 */


class State {
    public:
        virtual void Init()= 0;
        virtual void CleanUp() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(Game* game) = 0;
        virtual void Update(Game* game) = 0;
        virtual void Draw(Game* game) = 0;

        void changeState(Game* game, State* state) {
            game->ChangeState(state);
        }
    protected:
        State(){}
};

#endif // STATE_H
