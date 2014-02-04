#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
    delete spr;
    spr = 0;
}

AnimatedSprite* GameObject::getSprite(){
    return spr;
}

void GameObject::setSprite(AnimatedSprite* s){
    delete spr;
    spr = s;
}
