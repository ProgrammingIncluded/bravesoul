#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Stats.h"

class Character : public GameObject{
    public:
        Character(int mh = 100, int mm = 100, int ms = 100);

        Stats getStats();
        bool setStats(Stats stat);

        // Used for updating effects, will need to move it to field or some manager with current design
        // structure.
        void turnUpdate(){};
        void apply(std::vector<GameObject*> gos){};
        void apply(GameObject* go){};

        bool setAttackList(std::vector<int>atkList);
        std::vector<int>getAttackList();

    private:
        Stats stat;
        bool isDead;

        int maxWeapon;
        int maxAtk;

        std::vector<int>attackList;
        //Add weapon variable vector
};

#endif // CHARACTER_H
