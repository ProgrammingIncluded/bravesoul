#ifndef STATE_H
#define STATE_H

#include "StateManager.h"

/**
 * States manage themselves. Are their own factory, creates other states, etc.
 * Abstract class.
 */


class State {
    public:
        virtual void Init(StateManager* stateM)= 0;
        virtual void CleanUp() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(StateManager* game) = 0;
        virtual void Update(StateManager* game) = 0;
        virtual void Draw(StateManager* game) = 0;

        void changeState(StateManager* game, State* state) {
            game->ChangeState(state);
        }
    protected:
        State(){}
};

#endif // STATE_H
