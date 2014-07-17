#include "Character.h"

Character::Character(int mh, int mm, int ms)
{
    stat.setHp(mh);
    stat.setMp(mm);
    stat.setStr(ms);

    maxWeapon = 1;
}

Stats Character::getStats()
{
    return stat;
}

bool Character::setStats(Stats stat)
{
    this->stat = stat;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Character& ca)
{
    os << ca.getName();
    return os;
}

std::vector<int> Character::getAttackList()
{
    return attackList;
}

bool Character::setAttackList(std::vector<int>atkList)
{
    if(atkList.size() == 0)
    {
        return false;
    }

    attackList = atkList;
    return true;
}

