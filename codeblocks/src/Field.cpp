#include "Field.h"

Field::Field(Map* lvl)
{
    AttackD::loadCAttacks();
    // Fix after addMap is implemented
    if(lvl == nullptr)
    {

    }
    level = lvl;
}

Field::~Field()
{
    //dtor
    AttackD::clearAttacks();
}

bool Field::addChar(Character::charPtr ch, sf::Vector3i loc)
{
    if(ch == nullptr)
    {
        return false;
    }
    level->addGO(ch, loc);
    return true;
}

bool Field::attack(sf::Vector3i atker, sf::Vector3i rec, Attack atk)
{
    Character::charPtr attacker = level->getGO(atker);
    Character::charPtr receiver = level->getGO(rec);
    if(attacker == nullptr || receiver == nullptr) //Add return nullptr in map and check here.
    {
        return false;
    }

    Attack atck = AttackD::getAttack(0);
    atck.apply(attacker,receiver);

    // Check if character is dead. Will replace with custom check function for more options.
    if(attacker->getStats().getHp() <= 0)
    {
        level->removeGO(atker);
    }
    if(receiver->getStats().getHp() <= 0)
    {
        level->removeGO(rec);
    }

    return true;
}
