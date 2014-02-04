#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

<<<<<<< HEAD:codeblocks/include/GameObject.h
#include <vector>
#include "AnimatedSprite.h"
#include "Attack.h"

class GameObject{
=======
>>>>>>> parent of e6eb7aa... Added game logic framework.:codeblocks/include/gameObject.h

class gameObject
{
public:
<<<<<<< HEAD:codeblocks/include/GameObject.h
    GameObject();
    ~GameObject();

    AnimatedSprite* getSprite();

    void setSprite(AnimatedSprite* s);

private:

    AnimatedSprite* spr;
    std::vector<enum_effect>effects;

=======
    gameObject();
    ~gameObject();
protected:
private:
>>>>>>> parent of e6eb7aa... Added game logic framework.:codeblocks/include/gameObject.h
};

#endif // GAMEOBJECT_H
