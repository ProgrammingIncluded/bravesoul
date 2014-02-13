#ifndef ABILITIES_H
#define ABILITIES_H

enum ability_type{
    hadouken,
    heal,
    regen,
    kameha
};

#include "Offense.h"


class Abilities : Offense
{
    public:
        Abilities();

    private:

};

#endif // ABILITIES_H
