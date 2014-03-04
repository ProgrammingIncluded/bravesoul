#ifndef TDSCENE_H
#define TDSCENE_H

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "AnimatedSprite.h"
#include "Animation.h"



class TDScene : public Scene<AnimatedSprite*>
{
    public:
        TDScene();
        ~TDScene();

        bool setAnimation(Animation* a);

    private:
        Animation* anim;
};

#endif // TDSCENE_H
