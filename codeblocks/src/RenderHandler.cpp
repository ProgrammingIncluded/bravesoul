#include "RenderHandler.h"

typedef std::shared_ptr<sf::Texture> txPtr;

RenderHandler& RenderHandler::getInstance(){
    static RenderHandler rhInstance;
    return rhInstance;
}

RenderHandler::RenderHandler()
{
    screenDimensions = sf::Vector2i(800,600);
    render = new sf::RenderWindow(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    render->resetGLStates();
    sfGui = new sfg::SFGUI();
    desktop = new sfg::Desktop();
    texList.reserve(100);
}

RenderHandler::~RenderHandler()
{
    desktop->RemoveAll();
    delete desktop;
    desktop = nullptr;

    delete sfGui;
    sfGui = nullptr;

    delete render;
    render = nullptr;
}

sf::RenderWindow* RenderHandler::getRenderWindow(){
    return render;
}

void RenderHandler::draw(const sf::Color &color)
{
    sf::Time frameTime = clock.restart();
    desktop->Update(frameTime.asSeconds());
    render->clear(color);

    for(auto it = animQueue.begin(); it != animQueue.end(); ++it)
    {
        (*it)->update(frameTime);
        render->draw(**it);
    }

    for(auto it = drawQueue.begin(); it != drawQueue.end(); ++it)
    {
        render->draw(**it);
    }

    sfGui->Display(*render);
    render->display();

    drawQueue.clear();
    animQueue.clear();
}

void RenderHandler::addRender(sf::Drawable& drawable)
{
    drawQueue.push_back(&drawable);
}

void RenderHandler::addRender(GameObject* go)
{
    animQueue.push_back(go->getAnimatedSprite());
}

void RenderHandler::addRender(Map* m)
{
    animQueue.push_back(m->getBackground()->getScene());

    // Returns an animation sprite
    auto sprs = m->getSpriteRender();
    for(auto it = sprs->begin(); it != sprs->end(); ++it)
    {
       animQueue.push_back(it->second);
    }

}

void RenderHandler::addRender(sfg::Widget::Ptr widget){
    addWidget(widget);
}

// Draw directly?
void RenderHandler::addRender(const std::vector<sf::Shape*>&shape)
{
    for(auto it = shape.begin(); it != shape.end(); ++it)
    {
        drawQueue.push_back(&**it);
    }
}

sf::Texture& RenderHandler::addTexture(std::string file){
    auto it = texList.find(file);

    if(it != texList.end()){
        return *it->second;
    }
    else {
        txPtr tex(new sf::Texture());
        if(!tex->loadFromFile(file))
        {
            tex->loadFromFile("assets/general/player.png");
        }
        texList[file] = tex;
        return *tex;
    }
}

void RenderHandler::clearBuffer(){
    render->clear();
    texList.clear();
}

// sfgui related functions.

sfg::Desktop* RenderHandler::getGUIDesktop(){
    return this->desktop;
}

void RenderHandler::handleGUI(sf::Event event){
    desktop->HandleEvent(event);
}

void RenderHandler::addWidget(sfg::Widget::Ptr widget){
    desktop->Add(widget);
    desktop->Refresh(); // <= very unreliable if multi widgets
}


void RenderHandler::setWidgetColor(std::string selector, std::string prop, sf::Color clr){
    desktop->SetProperty(selector, prop, clr);
}
