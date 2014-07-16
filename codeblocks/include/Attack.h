#ifndef ATTACK_H
#define ATTACK_H

class Character;
class Effect;

#include <map>
#include "Damage.h"
#include "EffectEnum.h"

/**
* Attack class used to calculate effects and damage.
* GameObject use this class to send attack packets.
* Why damage class instead of simple primitive? May be
* used for modibility of what variable can be affected via
* external script. As well as modibility. May change to primitive
* if optimization.
*
*/

class Attack
{
    public:

        Attack();

        // Perhaps un-needed for multi parameter character?
        void apply(Character* attkr, Character* rec);

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

        static Effect* enumToClass(enum_effect ef);
};

#endif // ATTACK_H
