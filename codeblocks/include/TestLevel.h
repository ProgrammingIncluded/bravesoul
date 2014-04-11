#ifndef TESTLEVEL_H
#define TESTLEVEL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "State.h"
#include "Map.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Character.h"

class TestLevel : public State
{
    public:
        void Init();
        void CleanUp();
        void Pause();
        void Resume();

        void HandleEvents(Game* game);
        void Update(Game* game);
        void Draw(Game* game);

        static TestLevel& getInstance();

    protected:
        TestLevel(){}
        TestLevel(TestLevel const&);

    private:
        RenderHandler* ren;
        AudioHandler* auh;

        Map* level;
        std::vector<Character*> arrayChar;

        sf::Time frameTime;
        sf::Clock frameClock;

        float speed;
        bool noKeyWasPressed;
        bool isMapMov;
        bool isMouseMov;
        int backMusic; // Will not be final.

        Animation walkingAnimationDown;

        sf::RenderWindow* window;

        void operator=(TestLevel const&);

};

#endif // TESTLEVEL_H
