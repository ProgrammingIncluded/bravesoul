#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Stats.h"

class Character : public GameObject{
    public:
        Character(int mh = 100, int mm = 100, int ms = 100);

        int getHp();
        int getMp();
        int getStr();

    private:
        Stats stat;

        int maxWeapon;
        //Add weapon variable vector
};

#endif // CHARACTER_H
