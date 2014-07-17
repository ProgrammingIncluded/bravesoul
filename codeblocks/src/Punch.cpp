#include "Punch.h"

Punch::Punch()
{
    this->name = "Falco Punch";
    this->atk = Attack();
    Damage dmg = Damage();
    dmg.hp = 100;
    this->atk.addDamage(dmg);
}

Punch::~Punch()
{
    //dtor
}
