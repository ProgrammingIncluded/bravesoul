#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include "Character.h"
#include "RenderHandler.h"
#include "AudioHandler.h"
#include "Map.h"



int main()
{
    // setup window
    sf::Vector2i screenDimensions(800, 600);
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");

    window->setVerticalSyncEnabled(true);
    RenderHandler* renderHandler = new RenderHandler(window);

    // load texture (spritesheet)
    sf::Texture texture = renderHandler->addTexture("assets/general/player.png");
    // set up the animations for all four directions (set spritesheet and push frames)
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    Map* level = new Map(sf::Vector3i(500,500,2));
    level->setScene(renderHandler->addTexture("assets/general/testmap.png"));
    level->setMapPosition(sf::Vector3f(100,100,0),sf::Vector3f(0,0,0));

    std::vector<Character*> arrayChar;
    //Try Gameobject class
    for(int i = 0; i <= 1; i++){
        for(int x = 0; x <= 0; x++){
            Character* steve = new Character();
            steve->setAnimation(walkingAnimationDown);
            arrayChar.push_back(steve);
            level->addGO(steve, sf::Vector2i(i,x));
        }
    }

    sf::Clock frameClock;
    sf::Event *event;

    float speed = 80.f;
    bool noKeyWasPressed = true;
    bool isMapMov = false;
    bool isMouseMov = false;

    // Test AudioHandler
    AudioHandler* auh = new AudioHandler();
    int s1 = auh->loadSound("assets/audio/Page Turn.wav");
    auh->playMusic("assets/audio/Yosuga No Sora OST 1.wav");
    //auh->playMusic("assets/audio/conquest.wav");
    std::cout << "AudioHandler index used: " << s1 << std::endl;
    std::cout << "Press q to turn a page." << std::endl;
    std::cout << "Press e to play music." << std::endl;
    std::cout << "Press r to pause music." << std::endl;
    std::cout << "Press x to increase volume." << std::endl;
    std::cout << "Press z to decrease volume." << std::endl;
    std::cout << "Press t to change render option." << std::endl;
    std::cout << "Press l to lock/unlock mouse movement" << std::endl;
    std::cout << "Mouse wheel to zoom in or out." << std::endl;

    while (window->isOpen())
    {
        event = new sf::Event();
        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
                window->close();
            if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape)
                window->close();
        }

        sf::Time frameTime = frameClock.restart();

        if(event->type == sf::Event::KeyReleased) {
            if(event->key.code == sf::Keyboard::Q) {
                auh->playSound(s1);
            }
            if(event->key.code == sf::Keyboard::E) {
                auh->playMusic();
            }
            if(event->key.code == sf::Keyboard::R) {
                auh->pauseMusic();
            }
            if(event->key.code == sf::Keyboard::X) {
                auh->setVolume(auh->getVolume() + 5);
                std::cout << "\tVolume is " << auh->getVolume() << "\n";
            }
            if(event->key.code == sf::Keyboard::Z) {
                auh->setVolume(auh->getVolume() - 5);
                std::cout << "\tVolume is " << auh->getVolume() << "\n";
            }

            if(event->key.code == sf::Keyboard::T){
                if(isMapMov){
                    isMapMov = false;
                    std::cout << "Now using renderview movement." << std::endl;
                }
                else{
                    isMapMov = true;
                    std::cout << "Now using physical Map movement." << std::endl;
                }
            }

            if(event->key.code == sf::Keyboard::L){
                if(isMouseMov){
                    isMouseMov = false;
                    std::cout << "Mouse move disabled" << std::endl;
                }
                else {
                    isMouseMov = true;
                    std::cout << "Mouse move enabled." << std::endl;
                }
            }
        }

        sf::View view = window->getView();
        int movSpd = 2;
        float zmSpd = 0.1;
        int moveBar = 120;

        if(isMapMov){
             sf::Vector3f pos = level->getMapPos();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                pos.x-=movSpd;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                pos.x+=movSpd;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                pos.y+=movSpd;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                pos.y-=movSpd;
            }

            level->setMapPosition(pos, sf::Vector3f(0,0,0));
        }
       else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                view.move(movSpd,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                view.move(-movSpd,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                view.move(0,-movSpd);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                view.move(0,movSpd);
            }

        }

        if(event->type == sf::Event::MouseWheelMoved ) {
            if(event->mouseWheel.delta == -1){
                view.zoom(zmSpd +1);
            }
            else if(event->mouseWheel.delta == 1){
                view.zoom(1-zmSpd);
            }
        }

        if(isMouseMov){
            float x = sf::Mouse::getPosition(*window).x;
            float y = sf::Mouse::getPosition(*window).y;
            float sh = window->getSize().x;
            float sw = window->getSize().y;
            if(  sh-moveBar < x ) {
                view.move(movSpd,0);
            }
            if(  x < moveBar) {
                view.move(-movSpd,0);
            }
            if(  sw-moveBar < y ) {
                view.move(0,movSpd);
            }
            if(  y < moveBar) {
                view.move(0,-movSpd);
            }
        }
        window->setView(view);

        renderHandler->addRender(level);
        renderHandler->update(frameTime);

        delete event;
    }

    delete renderHandler;
    renderHandler = nullptr;

    delete auh;
    auh = nullptr;

    delete level;
    level = nullptr;

    delete window;
    window = nullptr;

    for(int x =0; x< arrayChar.size(); x++){
        delete arrayChar[x];
    }

    return 0;
}
