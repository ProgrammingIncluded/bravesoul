#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
#include "AnimatedSprite.h"
#include "GameObject.h"
#include "Map.h"


class RenderHandler
{
public:
    static RenderHandler& getInstance();

    sf::RenderWindow* getRenderWindow();

    void update(sf::Time frameTime);
    void addRender(sf::Sprite spr); // Todo, create sprite out of animation.
    void addRender(AnimatedSprite* spr);
    void addRender(GameObject* go);
    void addRender(Map* m);

    sf::Texture& addTexture(std::string file);
    sf::Texture getTexture(int index);

    void clearBuffer();

private:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>>texList;

    std::vector<sf::Sprite>spriteQueue;
    std::vector<AnimatedSprite*>animationQueue;

    sf::Vector2i screenDimensions;

    sf::RenderWindow* render;

    RenderHandler();
    RenderHandler(RenderHandler const&);
    void operator=(RenderHandler const&);
    ~RenderHandler();
};

#endif // RENDERHANDLER_H
