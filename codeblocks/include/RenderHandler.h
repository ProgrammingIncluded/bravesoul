#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

#include <SFML/Graphics.hpp>

class RenderHandler
{
public:
    RenderHandler(sf::RenderWindow* r);
    ~RenderHandler();

    void update();
    void addRender(sf::Sprite spr);

private:
    std::vector<sf::Sprite>spriteQueue;
    sf::RenderWindow* render;
};

#endif // RENDERHANDLER_H
