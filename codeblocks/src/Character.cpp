#include "Character.h"

Character::Character(int h, int m, int s):
maxhp(h), maxmp(m), maxstr(s)
{
    hp = maxhp;
    mp = maxmp;
    str = maxstr;
    maxWeapon = 1;
}
