#ifndef ATTACK_H
#define ATTACK_H

/**
* Attack class used to calculate effects and damage.
* gameObject use this class to send attack packets.
*
*/


enum enum_effect{
    frozen,
    heat,
    poison,
    rust,
    confused
};

#include "Effect.h"
#include <map>
#include "Damage.h"
#include "gameObject.h"

class Effect; //Used since effect, attack, and gameObject have a loop include. Give errors... Codeblocks...

class Attack
{
    public:

        Attack();

        void apply();

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
