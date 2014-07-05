#include "Intro.h"

void Intro::Init(StateManager* stateM){
    // For now, just go to menu
    screenCounter = 0;
    render = &RenderHandler::getInstance();

    splash.setTexture(render->addTexture("assets/general/logo.png"));
    splash.setScale(0.5f,0.5f);
    sf::FloatRect sprRect = splash.getLocalBounds();
    splash.setOrigin(sprRect.left + sprRect.width/2.0f, sprRect.top + sprRect.height/2.0f);
    splash.setPosition(sf::Vector2f(render->SCREEN_WIDTH/2,render->SCREEN_HEIGHT/2));

    AudioHandler* auh = &AudioHandler::getInstance();
    auh->loadMusic("assets/audio/Innoncence Charles Cover.wav");
    auh->playMusic();
}

void Intro::CleanUp(){
    // Need to fix this
    //render->clearBuffer();

}

void Intro::Pause(){

}

void Intro::Resume(){

}

void Intro::HandleEvents(StateManager* stateM){
    sf::Event event;

    if(screenCounter > 255){
        stateM->ChangeState(Menu::getInstance());
    }

    while(render->getRenderWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            stateM->Quit();
        }
        else if(event.type == sf::Event::MouseButtonPressed
            || event.type == sf::Event::KeyPressed){
            stateM->ChangeState(Menu::getInstance());
        }
    }
}

void Intro::Update(StateManager* stateM){
    float sec = time.restart().asSeconds()*60;

    sf::Color color = splash.getColor();
    color.a = screenCounter + 10;

    screenCounter += sec;

    splash.setColor(color);

    render->addRender(splash);
    //screenCounter += 0.01;
}

void Intro::Draw(StateManager* stateM){
    render->draw(sf::Color(255,255,255,255));
}

