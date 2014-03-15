#include "TestLevel.h"


TestLevel& TestLevel::getInstance(){
    static TestLevel testState;
    return testState;
}

void TestLevel::Init(){
    speed = 80.0f;
    noKeyWasPressed = true;
    isMapMov = false;
    isMouseMov = false;

    auh = &AudioHandler::getInstance();
    ren = &RenderHandler::getInstance();
    window = ren->getRenderWindow();

    backMusic = auh->loadSound("assets/audio/Page Turn.wav");
    auh->playMusic("assets/audio/Yosuga No Sora OST 1.wav");

    std::cout << "AudioHandler index used: " << backMusic << std::endl;
    std::cout << "Press q to turn a page." << std::endl;
    std::cout << "Press e to play music." << std::endl;
    std::cout << "Press r to pause music." << std::endl;
    std::cout << "Press x to increase volume." << std::endl;
    std::cout << "Press z to decrease volume." << std::endl;
    std::cout << "Press t to change render option." << std::endl;
    std::cout << "Press l to lock/unlock mouse movement" << std::endl;
    std::cout << "Mouse wheel to zoom in or out." << std::endl;

    walkingAnimationDown.setSpriteSheet(ren->addTexture("assets/general/player.png"));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    level = new Map(sf::Vector3i(500,500,2));
    level->setScene(ren->addTexture("assets/general/testmap.png"));
    level->setMapPosition(sf::Vector3f(100,100,0),sf::Vector3f(0,0,0));

    for(int i = 0; i <= 1; i++){
        for(int x = 0; x <= 0; x++){
            Character* steve = new Character();
            steve->setAnimation(walkingAnimationDown);
            arrayChar.push_back(steve);
            level->addGO(steve, sf::Vector2i(i,x));
        }
    }
}

void TestLevel::CleanUp(){
    ren = nullptr;
    auh = nullptr;
    delete level;
    level = nullptr;
    for(int x =0; x< arrayChar.size(); x++){
        delete arrayChar[x];
    }
}

void TestLevel::Pause(){

}

void TestLevel::Resume(){

}

void TestLevel::HandleEvents(Game* game){
    event = new sf::Event();

    // Move to Game Class for Global?
    while (window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed){
            window->close();
            game->Quit();
        }
        if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape)
        {
            window->close();
            game->Quit();
        }
    }

    frameTime = frameClock.restart();

    if(event->type == sf::Event::KeyReleased) {
        if(event->key.code == sf::Keyboard::Q) {
            auh->playSound(backMusic);
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

    delete event;
    event = nullptr;
}

void TestLevel::Update(Game* game){
    //May put more info here.
}

void TestLevel::Draw(Game* game){
    ren->addRender(level);
    ren->update(frameTime);
}