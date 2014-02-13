#include "Damage.h"

Damage::Damage()
{
    hp = 0;
    mp = 0;
    stm = 0;
}


Damage operator+(const Damage & a, const Damage & b){
    Damage r;

    r.hp = a.hp + b.hp;
    r.mp = a.mp + b.mp;
    r.stm = a.stm + b.stm;
    return r;
}

Damage operator-(const Damage & a, const Damage & b){
    Damage r;

    r.hp = a.hp + -b.hp;
    r.mp = a.mp + -b.mp;
    r.stm = a.stm + -b.stm;
    return r;
}

Damage operator*(const Damage & a, const Damage & b){
    Damage r;

    r.hp = a.hp * b.hp;
    r.mp = a.mp * b.mp;
    r.stm = a.stm * b.stm;
    return r;
}

Damage operator/(const Damage & a, const Damage & b){
    Damage r;

    r.hp = a.hp / b.hp;
    r.mp = a.mp / b.mp;
    r.stm = a.stm / b.stm;
    return r;
}
