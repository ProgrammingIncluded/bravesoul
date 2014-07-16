#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class AnimatedSprite;

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Animation.h"
#include "AnimatedSprite.h"
#include "EffectEnum.h"

class GameObject{

public:
    GameObject();
    virtual ~GameObject();

    Animation getAnimation();
    void setAnimation(Animation s);

    AnimatedSprite* getAnimatedSprite();

    virtual void turnUpdate() = 0;
    virtual void apply(std::vector<GameObject*> gos) = 0;
    virtual void apply(GameObject* go) = 0;

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
