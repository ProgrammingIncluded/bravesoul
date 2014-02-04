#include "gameObject.h"

gameObject::gameObject()
{

}

gameObject::~gameObject()
{
    delete spr;
    spr = 0;
}

AnimatedSprite* gameObject::getSprite(){
    return spr;
}

void gameObject::setSprite(AnimatedSprite* s){
    delete spr;
    spr = s;
}
