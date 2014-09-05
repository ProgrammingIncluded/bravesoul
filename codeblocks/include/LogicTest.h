#ifndef LOGICTEST_H
#define LOGICTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "StateManager.h"
#include "State.h"
#include "Map.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Character.h"
#include "Field.h"
#include "Attack.h"

class LogicTest : public State
{
    public:
        void Init(StateManager* stateM);
        void CleanUp();
        void Pause();
        void Resume();

        void HandleEvents(StateManager* game);
        void Update(StateManager* game);
        void Draw(StateManager* game);

        static LogicTest& getInstance();

    protected:
        LogicTest(){}
        LogicTest(LogicTest const&);

    private:
        RenderHandler* ren;
        AudioHandler* auh;

        Map* level;
        Field* field;
        // Field should be in charge of characters.
        std::vector<Character::charPtr> arrayChar;

        sf::Time frameTime;
        sf::Clock frameClock;

        Animation walkingAnimationDown;

        sf::RenderWindow* window;

        void operator=(LogicTest const&);

        void attackButton();
};

#endif // LOGICTEST_H
