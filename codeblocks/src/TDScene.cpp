#include "TDScene.h"

TDScene::TDScene():TDScene::Scene<AnimatedSprite*>(d){
    d = new AnimatedSprite();
    //Add default animation
}

TDScene::~TDScene(){
    delete anim;
    anim = nullptr;

    delete d;
    d = nullptr;
}

bool TDScene::setAnimation(Animation* a){
    anim = a;
    d->stop();
    d->setAnimation(*a);
    d->play();
    return true;
}
