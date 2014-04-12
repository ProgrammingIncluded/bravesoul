#ifndef INTRO_H
#define INTRO_H

#include "State.h"
#include "StateManager.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Menu.h"

class Intro : public State
{
    public:
        static Intro* getInstance(){
            static Intro bState;
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
        Intro(){};
        Intro(Intro const&);
        void operator=(Intro const&);
        ~Intro(){};

    private:
        RenderHandler* render;
        StateManager* stateM;
        float screenCounter;
        sf::Clock time;
        sf::Sprite splash;

};

#endif // INTRO_H
