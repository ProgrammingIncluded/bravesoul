#ifndef ATTACKD_H
#define ATTACKD_H


#include <vector>
#include "Attack.h"

class AttackD
{
    public:
        AttackD();
        virtual ~AttackD();

        // List of attacks hard coded into C++ needs to be loaded via this func.
        // List of attacks for LUA file is another function.
        static bool loadCAttacks();
        // Given an attack type, returns the index of attack. Note: no checking
        // of duplicate attack occurs. Need to fix..
        static int addAttackType(AttackD* atk);
        static bool clearAttacks();

        static Attack getAttack(int index);

        Attack getAtk();
        std::string getName();

    protected:
        std::string name;
        Attack atk;

    private:
        static std::vector<AttackD*>atkIndexList;
};

#endif // ATTACKD_H
