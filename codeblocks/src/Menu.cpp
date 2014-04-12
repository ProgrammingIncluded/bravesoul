#include "Menu.h"

void Menu::Init(StateManager* stateM){
    render = &RenderHandler::getInstance();
    this->stateM = stateM;

    // Button Set Id
    sfg::Button::Ptr idButton = sfg::Button::Create("Start Test Stage");
    idButton->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &Menu::clickStartGame, this ) );
    idButton->SetId("createId");

    // SQLGenerator Button
    sfg::Button::Ptr sqlGenButton = sfg::Button::Create("Custom Game");
    sqlGenButton->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &Menu::clickCustomGame, this ) );
    sqlGenButton->SetId("customGame");

    sfg::Button::Ptr quitButton = sfg::Button::Create("Quit");
    quitButton ->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &StateManager::Quit, this->stateM ) );
    quitButton ->SetId("quit");

    // Title Label
    sfg::Label::Ptr label = sfg::Label::Create("BVSL Alpha 1.0");
    label->SetId("appTitle");
    render->getGUIDesktop()->SetProperty("#appTitle", "FontSize", 20);

    //Create Box and Add Buttons
    sfg::Box::Ptr box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
    box->SetId("titleBox");
    box->SetSpacing(25.0f);

    box->Pack(label);
    box->Pack(idButton);
    box->Pack(sqlGenButton);
    box->Pack(quitButton);

    //Set up menu window
    sfg::Window::Ptr  window = sfg::Window::Create();
    window->SetId("title");
    window->SetStyle(window->GetStyle() ^ sfg::Window::TITLEBAR);
    window->SetStyle(window->GetStyle() ^ sfg::Window::RESIZE);

    // Add Box
    window->Add(box);

    window->SetPosition(sf::Vector2f(
			static_cast<float>( RenderHandler::SCREEN_WIDTH/2) - window->GetAllocation().width / 2.f,
			static_cast<float>( RenderHandler::SCREEN_HEIGHT/2) - window->GetAllocation().height / 2.f
		));

    render->addWidget(window);

    // Added audio because why not..

}

void Menu::CleanUp(){
    // Should child also be removed?

    render->getGUIDesktop()->RemoveAll();
    AudioHandler::getInstance().pauseMusic();
    // Only singleton owns it, so delete is ok safe.Others don't have pointer
    //Hence other pointers are destroyed.


}

void Menu::Pause(){

}

void Menu::Resume(){

}

void Menu::HandleEvents(StateManager* stateM){
    sf::Event event;
    sfg::Widget::Ptr window = sfg::Widget::GetWidgetById("title");

    while(render->getRenderWindow()->pollEvent(event)){
        render->handleGUI(event);

        if(event.type == sf::Event::Closed){
            stateM->Quit();
        }

        //Center title in center
        if(event.type == sf::Event::Resized){
            window->SetPosition(sf::Vector2f(
                static_cast<float>( render->getRenderWindow()->getSize().x/2) - window->GetAllocation().width / 2.f,
                static_cast<float>( render->getRenderWindow()->getSize().y/2) - window->GetAllocation().height / 2.f
            ));
        }
    }
}

void Menu::Update(StateManager* stateM){

}

void Menu::Draw(StateManager* stateM){
    render->draw();
}

//**Button Functions**//
// I could create a system to automatically add buttons and link to same functions.
// However the research and effort is A) too time risky, B) unnecessary in this project,
// C) probably more complicated than I deduce.

void Menu::clickStartGame(){
    stateM->PopState();
    stateM->ChangeState(&TestLevel::getInstance());
}

void Menu::clickCustomGame(){
    stateM->PopState();
    stateM->ChangeState(&TestLevel::getInstance());
}

