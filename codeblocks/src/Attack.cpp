#include "Attack.h"
#include "Frozen.h"

Attack::Attack()
{
    //ctor
}

void Attack::apply(){
    //tes
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
