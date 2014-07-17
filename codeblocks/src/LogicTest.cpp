#include "LogicTest.h"


LogicTest& LogicTest::getInstance(){
    static LogicTest testState;
    return testState;
}

void LogicTest::Init(StateManager* stateM){

    ren = &RenderHandler::getInstance();
    window = ren->getRenderWindow();


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
            steve->setName("Steve");
            steve->setAnimation(walkingAnimationDown);
            arrayChar.push_back(steve);
            level->addGO(steve, sf::Vector2i(i,x));
        }
    }

    field = new Field(level);

    // Set Up GUI
    sfg::Button::Ptr attkButton = sfg::Button::Create("Attack!");
    attkButton->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &LogicTest::attackButton, this ) );
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

void LogicTest::CleanUp(){
    ren = nullptr;
    auh = nullptr;
    delete field;
    field = nullptr;
    delete level;
    level = nullptr;
    for(int x =0; x< arrayChar.size(); x++){
        delete arrayChar[x];
    }
}

void LogicTest::Pause(){

}

void LogicTest::Resume(){

}

void LogicTest::HandleEvents(StateManager* StateManager){
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
        if(event.key.code == sf::Keyboard::R){
            std::cout << "Key board works!" << std::endl;
        }
    }

    sf::View view = window->getView();
    int movSpd = 1+60*frameTime.asSeconds();
    float zmSpd = 0.1;
    int moveBar = 120;

    if(event.type == sf::Event::MouseWheelMoved ) {
        if(event.mouseWheel.delta == -1){
            view.zoom(zmSpd +1);
        }
        else if(event.mouseWheel.delta == 1){
            view.zoom(1-zmSpd);
        }
    }

    window->setView(view);
}

void LogicTest::Update(StateManager* StateManager){
    //May put more info here.
}

void LogicTest::Draw(StateManager* StateManager){
    ren->addRender(level);
    ren->draw();
}

void LogicTest::attackButton(){
    field->attack(sf::Vector3i(0,0,0),sf::Vector3i(1,0,0), Attack());
}
