#ifndef PUNCH_H
#define PUNCH_H

#include "AttackD.h"

class Punch : public AttackD
{
    public:
        Punch();
        virtual ~Punch();

        Attack getAtk();
};

#endif // PUNCH_H
