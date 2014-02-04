#ifndef FROZEN_H
#define FROZEN_H

#include "Effect.h"

class Frozen : public Effect
{
    public:
        Frozen();
        ~Frozen();

        void affect(GameObject* ob, int str);
};

#endif // FROZEN_H
