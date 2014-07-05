#ifndef ATTACK_H
#define ATTACK_H

#include <map>
#include "Character.h"
#include "Effect.h"
#include "Damage.h"

class Character;

/**
* Attack class used to calculate effects and damage.
* GameObject use this class to send attack packets.
*
*/

class Attack
{
    public:

        Attack();

        void apply(Character* ch);

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
