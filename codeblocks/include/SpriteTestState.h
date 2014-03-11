#ifndef SPRITETESTSTATE_H
#define SPRITETESTSTATE_H


class SpriteTestState : public State
{
    public:
        SpriteTestState();
        virtual ~SpriteTestState();
        State* run();
    private:
};

#endif // SPRITETESTSTATE_H
