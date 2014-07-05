#include "Stats.h"

Stats::Stats()
{
    maxhp = 100;
    maxmp = 100;
    maxstr = 100;
    maxexp = 9999;

    hp = 0;
    mp = 0;
    str = 0;
    exp = 0;
}

bool Stats::setHp(int hp){
    if(hp > maxhp){
        return false;
    }
    this->hp = hp;

    return true;
}

bool Stats::setMp(int mp){
    if(mp > maxmp){
        return false;
    }
    this->mp = mp;

    return true;
}

bool Stats::setStr(int str){
    if(str > maxstr){
        return false;
    }
    this->str = str;

    return true;
}

bool Stats::setExp(int exp){
    if(exp > maxexp){
        return false;
    }
    this->exp = exp;

    return true;
}
