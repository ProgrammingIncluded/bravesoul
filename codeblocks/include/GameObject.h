#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "AnimatedSprite.h"
#include "Attack.h"

class GameObject{

public:
    GameObject();
    ~GameObject();

    AnimatedSprite* getSprite();

    void setSprite(AnimatedSprite* s);

private:

    AnimatedSprite* spr;
    std::vector<enum_effect>effects;

};

#endif // GAMEOBJECT_H
