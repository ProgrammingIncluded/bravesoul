#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "AnimatedSprite.h"
#include "Animation.h"
#include "EffectEnum.h"

class GameObject{

public:
    GameObject();
    virtual ~GameObject();

    Animation getAnimation();
    void setAnimation(Animation s);

    AnimatedSprite* getAnimatedSprite();

    /*Mutators*/
    bool setName(std::string name);

    /*Accessors*/
    std::string getName() const;

private:
    // Should position be stored in GO as well?
    AnimatedSprite* spr;
    Animation anim;
    std::string name;
    std::vector<enum_effect>effects;
    sf::Vector3f position;

};

#endif // GAMEOBJECT_H
