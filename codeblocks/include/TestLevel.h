#ifndef TESTLEVEL_H
#define TESTLEVEL_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "StateManager.h"
#include "State.h"
#include "Map.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Character.h"
#include "Attack.h"
#include "HollowBox.h"

class TestLevel : public State
{
    public:
        void Init(StateManager* stateM);
        void CleanUp();
        void Pause();
        void Resume();

        void HandleEvents(StateManager* game);
        void Update(StateManager* game);
        void Draw(StateManager* game);

        static TestLevel& getInstance();

    protected:
        TestLevel(){}
        TestLevel(TestLevel const&);

    private:
        RenderHandler* ren;
        AudioHandler* auh;

        Map* level;
        std::vector<Character::charPtr> arrayChar;

        sf::Time frameTime;
        sf::Clock frameClock;

        float speed;
        bool noKeyWasPressed;
        bool isMapMov;
        bool isMouseMov;
        int backMusic; // Will not be final.

        Animation walkingAnimationDown;
        HollowBox* hollowBox;

        sf::RenderWindow* window;

        void operator=(TestLevel const&);

        void attackButton();
};

#endif // TESTLEVEL_H
