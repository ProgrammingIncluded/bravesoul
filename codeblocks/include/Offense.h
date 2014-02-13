#ifndef OFFENSE_H
#define OFFENSE_H

#include "GameObject.h"

class Offense : public GameObject
{
    public:
        Offense();

        //! Getters.
        int getCrit();
        int getHit();
        int getDef();
        int getDur();

        //! Setters.
        void setCrit(int c);
        void setHit(int h);
        void setDef(int d);
        void setDur(int d);

    private:
        int crit;
        int hit;
        int def;
        int dur;
};

#endif // OFFENSE_H
