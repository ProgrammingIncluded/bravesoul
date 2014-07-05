#include "GameObject.h"

GameObject::GameObject()
{
    sf::Vector3f defPos = sf::Vector3f(0,0,0);
    spr = new AnimatedSprite(sf::seconds(0.2), false, true);
    spr->setPosition(sf::Vector2f(defPos.x,defPos.y));
    name = "null";
    position = defPos;
}

GameObject::~GameObject()
{
    delete spr;
    spr = 0;
}

Animation GameObject::getAnimation(){
    return anim;
}

void GameObject::setAnimation(Animation s){
    anim = s;
    spr->setAnimation(anim);
}

AnimatedSprite* GameObject::getAnimatedSprite(){
    return spr;
}

bool GameObject::setName(std::string name)
{
    this->name = name;
    return true;
}

std::string GameObject::getName() const
{
    return name;
}
/*
sf::Vector3f GameObject::getPosition(){
    return position;
}

void GameObject::setPosition(sf::Vector3f vect){
    position = vect;
}

void GameObject::setPosition(sf::Vector2f vect){
    position = sf::Vector3f(vect.x,vect.y,position.z);
}
*/
