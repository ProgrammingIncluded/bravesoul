#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stdio.h>
#include <vector>

/// manages stack empty error, state errors

class State;

class StateManager
{
    public:
        StateManager();
        ~StateManager();
        void Init(const char* title, int width = 800,
            int height = 600, bool fullscreen = false);

        void Cleanup();

        void ChangeState(State* state);
        void PushState(State* state);
        void PopState();

        void HandleEvents();
        void Update();
        void Draw();

        bool Running();
        void Quit();

    private:
        std::vector<State*> states;

        bool isRunning;
};

#endif // STATEMANAGER_H
