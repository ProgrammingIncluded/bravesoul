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

void RenderHandler::draw()
{
    sf::Time frameTime = clock.restart();
    desktop->Update(frameTime.asSeconds());
    render->clear();

    for(int i = 0; i<spriteQueue.size(); i++)
    {
        render->draw(spriteQueue[i]);
    }

    for(int i = 0; i<animationQueue.size(); i++)
    {
        animationQueue[i]->update(frameTime);
        render->draw(*animationQueue[i]);
    }

    sfGui->Display(*render);
    render->display();

    spriteQueue.clear();
    animationQueue.clear();
}

void RenderHandler::addRender(sf::Sprite spr)
{
    spriteQueue.push_back(spr);
}

void RenderHandler::addRender(AnimatedSprite* spr)
{
    animationQueue.push_back(spr);
}

void RenderHandler::addRender(GameObject* go)
{
    animationQueue.push_back(go->getAnimatedSprite());
}

void RenderHandler::addRender(Map* m)
{
    animationQueue.push_back(m->getBackground()->getScene());

    // May change to pointers for less copying time
    std::vector<AnimatedSprite*>* sprs = m->getSpriteRender();
    for(int x = 0; x < sprs->size(); x++){
       animationQueue.push_back((*sprs)[x]);
    }

}

sf::Texture& RenderHandler::addTexture(std::string file){
   std::unordered_map<std::string, std::shared_ptr<sf::Texture>>::iterator it = texList.find(file);

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
