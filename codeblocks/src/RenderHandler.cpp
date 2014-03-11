#include "RenderHandler.h"

typedef std::shared_ptr<sf::Texture> txPtr;

RenderHandler::RenderHandler(sf::RenderWindow* r)
{
    render = r;
    texList.reserve(100);
}

RenderHandler::~RenderHandler()
{
    render = 0;
}

void RenderHandler::update(sf::Time frameTime)
{
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
    texList.clear();
}
