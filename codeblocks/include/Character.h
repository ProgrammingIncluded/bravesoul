#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"

class Character : public GameObject{
    public:
        Character(int mh = 100, int mm = 100, int ms = 100);

    private:
        int maxhp;
        int maxmp;
        int maxstr;

        int hp;
        int mp;
        int str;
        int exp;

        int maxWeapon;
        //Add weapon variable vector
};

#endif // CHARACTER_H
