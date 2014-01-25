#include "RenderHandler.h"

RenderHandler::RenderHandler(sf::RenderWindow* r)
{
    render = r;
}

RenderHandler::~RenderHandler()
{
    render = 0;
}

void RenderHandler::update()
{
    for(int i = 0; i<spriteQueue.size(); i++)
    {
        render->draw(spriteQueue[i]);
    }
}

void RenderHandler::addRender(sf::Sprite spr)
{
    spriteQueue.push_back(spr);
}
