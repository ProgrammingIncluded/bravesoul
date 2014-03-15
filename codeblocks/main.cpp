#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include "Character.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Map.h"
#include "AnimatedSprite.h"
#include "Game.h"
#include "TestLevel.h"


int main()
{
    Game game;

    game.Init("Test", 800,600,false);
    TestLevel* lvl = &TestLevel::getInstance();
    game.ChangeState(lvl);

    while(game.Running()){
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    game.Cleanup();


    return 0;
}
