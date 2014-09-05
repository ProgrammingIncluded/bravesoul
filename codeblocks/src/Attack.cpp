#include "Attack.h"
#include "Frozen.h"

Attack::Attack()
{
    //ctor
}

void Attack::apply(Character::charPtr attkr, Character::charPtr rec){
    // Add basic damage and add effects latter after testing new system.
    // Currently only simple attacks in one apply. Will add more after system works.
    Stats recStats = rec->getStats();
    recStats.setHp(recStats.getHp() - dmg.hp);
    recStats.setMp(recStats.getMp() - dmg.mp);
    recStats.setStr(recStats.getStr() - dmg.stm);
    rec->setStats(recStats);
}

void Attack::addDamage(Damage d){
    dmg = dmg + d;
}

void Attack::subtrDamage(Damage d){
    dmg = dmg - d;
}

void Attack::multDamage(Damage d){
    dmg = dmg * d;
}

Damage Attack::getDamage(){
    return dmg;
}

Effect* Attack::enumToClass(enum_effect ef){

    switch(ef){
        case frozen:
            Frozen* effect;
            return effect;
    }

}

void Attack::addEffect(enum_effect ef){
    effList[ef] += 1;
}

void Attack::subtrEffect(enum_effect ef){
    effList[ef] -= 1;
}

void Attack::removeEffect(enum_effect ef){
    effList.erase(ef);
}
