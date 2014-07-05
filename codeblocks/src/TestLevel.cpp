#include "TestLevel.h"


TestLevel& TestLevel::getInstance(){
    static TestLevel testState;
    return testState;
}

void TestLevel::Init(StateManager* stateM){
    speed = 80.0f;
    noKeyWasPressed = true;
    isMapMov = false;
    isMouseMov = false;

    auh = &AudioHandler::getInstance();
    ren = &RenderHandler::getInstance();
    window = ren->getRenderWindow();

    backMusic = auh->loadSound("assets/audio/Page Turn.wav");
    auh->playMusic("assets/audio/conquest.ogg");

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
        for(int x = 0; x <= 1; x++){
            Character* steve = new Character();
            steve->setAnimation(walkingAnimationDown);
            arrayChar.push_back(steve);
            level->addGO(steve, sf::Vector2i(i,x));
        }
    }

    // Set Up GUI
    sfg::Button::Ptr attkButton = sfg::Button::Create("Attack!");
    attkButton->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &TestLevel::attackButton, this ) );
    attkButton->SetId("Attack");

    sfg::Box::Ptr box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
    box->SetId("statsBox");
    box->SetSpacing(25.0f);
    box->Pack(attkButton);

    sfg::Window::Ptr  window = sfg::Window::Create();
    window->SetTitle("Commands");
    window->SetId("statsWindow");
    window->Add(box);

    ren->addRender(window);
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

void TestLevel::HandleEvents(StateManager* StateManager){
    sf::Event event = sf::Event();
    // Add Event Listener?

    // Move to StateManager Class for Global?
    while (window->pollEvent(event))
    {
        ren->handleGUI(event);
        if (event.type == sf::Event::Closed){
            window->close();
            StateManager->Quit();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window->close();
            StateManager->Quit();
        }
    }

    frameTime = frameClock.restart();

    if(event.type == sf::Event::KeyReleased) {
        if(event.key.code == sf::Keyboard::Q) {
            auh->playSound(backMusic);
        }
        if(event.key.code == sf::Keyboard::E) {
            auh->playMusic();
        }
        if(event.key.code == sf::Keyboard::R) {
            auh->pauseMusic();
        }
        if(event.key.code == sf::Keyboard::X) {
            auh->setVolume(auh->getVolume() + 5);
            std::cout << "\tVolume is " << auh->getVolume() << "\n";
        }
        if(event.key.code == sf::Keyboard::Z) {
            auh->setVolume(auh->getVolume() - 5);
            std::cout << "\tVolume is " << auh->getVolume() << "\n";
        }

        if(event.key.code == sf::Keyboard::T){
            if(isMapMov){
                isMapMov = false;
                std::cout << "Now using renderview movement." << std::endl;
            }
            else{
                isMapMov = true;
                std::cout << "Now using physical Map movement." << std::endl;
            }
        }

        if(event.key.code == sf::Keyboard::L){
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
    int movSpd = 1+60*frameTime.asSeconds();
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

    if(event.type == sf::Event::MouseWheelMoved ) {
        if(event.mouseWheel.delta == -1){
            view.zoom(zmSpd +1);
        }
        else if(event.mouseWheel.delta == 1){
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

    if(event.type == sf::Event::MouseButtonReleased){
        if(event.mouseButton.button == sf::Mouse::Left){
            //level->getGO(sf::Mouse::getPosition(*window), window->getDefaultView()->getCenter());
            std::cout << sf::Mouse::getPosition(*window).x << ", " << sf::Mouse::getPosition(*window).y << std::endl;
        }
    }

    window->setView(view);
}

void TestLevel::Update(StateManager* StateManager){
    //May put more info here.
}

void TestLevel::Draw(StateManager* StateManager){
    ren->addRender(level);
    ren->draw();
}

void TestLevel::attackButton(){
    Character* go = level->getGO(sf::Vector3i(0,0,0));
    Character* go2 = level->getGO(sf::Vector3i(1,0,0));
}
