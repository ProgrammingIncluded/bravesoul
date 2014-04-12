#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
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

    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

    sf::RenderWindow* getRenderWindow();

    void draw();
    void addRender(sf::Sprite spr); // Todo, create sprite out of animation.
    void addRender(AnimatedSprite* spr);
    void addRender(GameObject* go);
    void addRender(Map* m);

    sfg::Desktop* getGUIDesktop();

    void setWidgetColor(std::string selector, std::string prop, sf::Color clr);
    void handleGUI(sf::Event event);

    void addWidget(sfg::Widget::Ptr widget);


    sf::Texture& addTexture(std::string file);
    sf::Texture getTexture(int index);

    void clearBuffer();

private:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>>texList;

    std::vector<sf::Sprite>spriteQueue;
    std::vector<AnimatedSprite*>animationQueue;

    // May be depreacated
    sf::Vector2i screenDimensions;

    sf::RenderWindow* render;

    sfg::SFGUI* sfGui;
    sfg::Desktop* desktop;
    sf::Clock clock;

    RenderHandler();
    RenderHandler(RenderHandler const&);
    void operator=(RenderHandler const&);
    ~RenderHandler();
};

#endif // RENDERHANDLER_H
