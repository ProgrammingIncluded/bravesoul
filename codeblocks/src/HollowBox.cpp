#include "HollowBox.h"

HollowBox::HollowBox(const sf::Vector2f& sizeVect)
{
    polygon = new std::vector<sf::Shape*>;
    //Might be a problem when you try to access size after wards...
    sizeB = sizeVect;
    thickness = 1.0f;

    sf::ConvexShape* top = new sf::ConvexShape();
    top->setPointCount(4);
    sf::ConvexShape* bot = new sf::ConvexShape();
    bot->setPointCount(4);
    sf::ConvexShape* lft = new sf::ConvexShape();
    lft->setPointCount(4);
    sf::ConvexShape* rht = new sf::ConvexShape();
    rht->setPointCount(4);

    polygon->push_back(top);
    polygon->push_back(bot);
    polygon->push_back(lft);
    polygon->push_back(rht);

    update();
}

HollowBox::~HollowBox()
{
    for(auto it = polygon->begin(); it != polygon->end(); ++it)
    {
        delete *it;
        *it = nullptr;
    }
    delete polygon;
    polygon = nullptr;
}

const std::vector<sf::Shape*>& HollowBox::getShape()
{
    return *polygon;
}

void HollowBox::update()
{
    sf::Vector2f hSize(this->sizeB.x/2, this->sizeB.y/2);

    sf::ConvexShape* top = (sf::ConvexShape*)(*polygon)[0];
    sf::ConvexShape* bot = (sf::ConvexShape*)(*polygon)[1];
    sf::ConvexShape* lft = (sf::ConvexShape*)(*polygon)[2];
    sf::ConvexShape* rht = (sf::ConvexShape*)(*polygon)[3];

    top->setPoint(0, sf::Vector2f(-hSize.x,-hSize.y)); // Top left
    top->setPoint(1, sf::Vector2f(-hSize.x, -hSize.y + thickness)); // Bot left
    top->setPoint(2, sf::Vector2f(hSize.x, -hSize.y + thickness)); // Bot Right
    top->setPoint(3, sf::Vector2f(hSize.x,-hSize.y)); // Top Right

    bot->setPoint(0, sf::Vector2f(-hSize.x,hSize.y - thickness)); // Top left
    bot->setPoint(1, sf::Vector2f(-hSize.x, hSize.y)); // Bot left
    bot->setPoint(2, sf::Vector2f(hSize.x,hSize.y)); // Bot right
    bot->setPoint(3, sf::Vector2f(hSize.x,hSize.y - thickness)); // Top Right

    lft->setPoint(0, sf::Vector2f(hSize.x - thickness, -hSize.y + thickness)); // Top Left
    lft->setPoint(1, sf::Vector2f(hSize.x - thickness, hSize.y - thickness)); // Bot left
    lft->setPoint(2, sf::Vector2f(hSize.x, hSize.y - thickness)); // Bot right
    lft->setPoint(3, sf::Vector2f(hSize.x, -hSize.y + thickness)); // Top right

    rht->setPoint(0, sf::Vector2f(-hSize.x, -hSize.y + thickness)); // Top left
    rht->setPoint(1, sf::Vector2f(-hSize.x, hSize.y - thickness)); // Bot Left
    rht->setPoint(2, sf::Vector2f(-hSize.x + thickness, hSize.y - thickness)); // Bot right
    rht->setPoint(3, sf::Vector2f(-hSize.x + thickness, -hSize.y + thickness)); // Top right
}

// Getters and Setters
bool HollowBox::setThickness(float thick)
{
    if(thick > sizeB.x/2 || thick > sizeB.y/2)
    {
        return false;
    }
    thickness = thick;
    update();
    return true;
}

float HollowBox::getThickness()
{
    return thickness;
}

bool HollowBox::setSize(const sf::Vector2f& sizeHB)
{
    sizeB = sizeHB;
    update();
    return true;
}

const sf::Vector2f& HollowBox::getSize()
{
    return sizeB;
}
