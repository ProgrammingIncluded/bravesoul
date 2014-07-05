#ifndef STATS_H
#define STATS_H


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

    private:
        int hp;
        int mp;
        int str;
        int exp;
};

#endif // STATS_H
