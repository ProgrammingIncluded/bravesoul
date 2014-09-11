#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Vector3iCompare.h"
#include "AnimatedSprite.h"
#include "GameObject.h"
#include "Map.h"


// Singleton class in charge of communicating with SFML rendering.
// Acts a way for easier code portability and usage with SFML.
// Under heavy changes as RenderHandler depends on what the current
// program is and acts. Will require large change as of 9/7/2014

class RenderHandler
{
public:
    static RenderHandler& getInstance();

    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

    // Should not need to be used once everything is set in stone.
    sf::RenderWindow* getRenderWindow();

    void draw(const sf::Color &color= sf::Color(0, 0, 0, 255));
    void addRender(sf::Drawable& drawable); // Todo, create sprite out of animation.
    void addRender(GameObject* go);
    void addRender(Map* m);
    void addRender(sfg::Widget::Ptr widget);
    // Draw directly? Only func. that does not add to sec
    void addRender(const std::vector<sf::Shape*>& shape);

    sfg::Desktop* getGUIDesktop();

    void setWidgetColor(std::string selector, std::string prop, sf::Color clr);
    void handleGUI(sf::Event event);

    void addWidget(sfg::Widget::Ptr widget);


    sf::Texture& addTexture(std::string file);
    sf::Texture getTexture(int index);

    void clearBuffer();

private:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>>texList;

    // A second buffer may not be necessary. Double check code usage.
    // Too much queues, this is unecessary. Also, as draw types increase
    // vectors will also increase. Use SFML interface to communicate and
    // change all Drawables in to openGL. Or use drawable :P.
    std::vector<const sf::Drawable*>drawQueue;
    std::vector<AnimatedSprite*>animQueue;

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
