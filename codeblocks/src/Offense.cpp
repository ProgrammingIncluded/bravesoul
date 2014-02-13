#include "Offense.h"

Offense::Offense()
{
    crit = 0;
    hit = 0;
    def = 0;
    dur = 0;
}

int Offense::getCrit(){
    return crit;
}

int Offense::getHit(){
    return hit;
}

int Offense::getDef(){
    return def;
}

int Offense::getDur(){
    return dur;
}

void Offense::setCrit(int c){
    crit = c;
}

void Offense::setHit(int h){
    hit = h;
}

void Offense::setDef(int d){
    def = d;
}

void Offense::setDur(int d){
    dur = d;
}
