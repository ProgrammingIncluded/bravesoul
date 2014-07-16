#include "AttackD.h"
// You list of Attack needs to be included here via hard coded files.
// Find another way for c++ users... But this is mainly for developers. Recommend
// Lua files for adding new attack info.
#include "Punch.h"

std::vector<AttackD*>AttackD::atkIndexList = {};

AttackD::AttackD()
{
    //ctor
}

AttackD::~AttackD()
{
    //dtor
}

Attack AttackD::getAttack(int index)
{
    if(index >= atkIndexList.size() || index < 0 )
    {
        return Attack();
    }

    return atkIndexList[index]->getAtk();
}

bool AttackD::clearAttacks()
{
    if(atkIndexList.size() == 0)
    {
        return false;
    }
    atkIndexList.clear();
    return true;
}

bool AttackD::loadCAttacks()
{
    atkIndexList.push_back(new Punch());
}

int AttackD::addAttackType(AttackD* atk)
{
    atkIndexList.push_back(atk);
    return atkIndexList.size();
}

std::string AttackD::getName()
{
    return name;
}

Attack AttackD::getAtk()
{
    return atk;
}
