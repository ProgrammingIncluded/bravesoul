#ifndef Menu_H
#define Menu_H

#include "State.h"
#include "StateManager.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "TestLevel.h"

class Menu : public State
{
    public:
        static Menu* getInstance(){
            static Menu bState;
            return  &bState;
        }

        void Init(StateManager* stateM);
        void CleanUp();
        void Pause();
        void Resume();

        void HandleEvents(StateManager* state);
        void Update(StateManager* state);
        void Draw(StateManager* state);

    protected:
        Menu(){};
        Menu(Menu const&);
        void operator=(Menu const&);
        ~Menu(){};

    private:
        RenderHandler* render;
        StateManager* stateM;

        //Sgui - Attributes here incase you ever need it.

        //Button Function
        void clickStartGame();
        void clickCustomGame();

};

#endif // Menu_H
