#ifndef ATTACK_H
#define ATTACK_H

enum enum_effect{
    frozen,
    heat,
    poison,
    rust,
    confused
};

#include <map>
#include "Effect.h"
#include "Damage.h"
#include "GameObject.h"

class Effect; //Used since effect, attack, and GameObject have a loop include. Give errors... Codeblocks...
class GameObject;


/**
* Attack class used to calculate effects and damage.
* GameObject use this class to send attack packets.
*
*/

class Attack
{
    public:

        Attack();

        void apply(GameObject* go);

        void addDamage(Damage d);
        void subtrDamage(Damage d);
        void multDamage(Damage d);

        void addEffect(enum_effect ef);
        void subtrEffect(enum_effect ef);
        void removeEffect(enum_effect ef);

        Damage getDamage();

    private:
        Damage dmg;
        std::map<enum_effect,int>effList;

        Effect* enumToClass(enum_effect ef);
};

#endif // ATTACK_H
