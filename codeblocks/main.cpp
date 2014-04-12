#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include "Character.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Map.h"
#include "AnimatedSprite.h"
#include "StateManager.h"
#include "Intro.h"


int main()
{
    StateManager game;

    game.Init("Test", 800,600,false);
    Intro* lvl = Intro::getInstance();
    game.ChangeState(lvl);

    while(game.Running()){
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    game.Cleanup();


    return 0;
}
