#ifndef ATTACKTYPE_H
#define ATTACKTYPE_H

#import "Attack.h"

class AttackType
{
    public:
        static bool loadCAttacks();
        // Given an attack type, returns the index of attack.
        static int addAttackType(AttackType*);
        static bool clear(AttackType*);

        static Attack getAttack(int index);

        virtual Attack getAtk();

    private:
        static std::vector<AttackType*>atkIndexList;
};

#endif // ATTACKTYPE_H
