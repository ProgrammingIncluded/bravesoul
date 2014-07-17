#ifndef STATS_H
#define STATS_H

// For flexibilty, will change the class into a map for more modibility.

class Stats
{
    public:
        Stats();

        int maxhp;
        int maxmp;
        int maxstr;
        int maxexp;

        bool setHp(int hp);
        bool setMp(int mp);
        bool setStr(int str);
        bool setExp(int exp);

        int getHp();
        int getMp();
        int getStr();
        int getExp();

    private:
        int hp;
        int mp;
        int str;
        int exp;
};

#endif // STATS_H
