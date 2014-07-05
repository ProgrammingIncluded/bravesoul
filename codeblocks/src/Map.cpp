#include "Map.h"
#include <iostream>


Map::Map(sf::Vector3i mSize)
{
    // Size allocation is based on dimensions.
    spriteList = new std::vector<AnimatedSprite*>();
    startCorner = sf::Vector3f(0,0,0);
    mapPos = startCorner;
    endCorner = sf::Vector3f(1,1,0);
    mSize.x += 1;
    mSize.y += 1;
    mSize.z += 1;

    spacing = 30;

    this->mSize = mSize;
    mapList.resize(mSize.x);
    for(int i = 0; i < mSize.x; i++){
        mapList[i].resize(mSize.y);

        for(int x=0; x < mSize.y; x++ ){
            mapList[i][x].resize(mSize.z);
        }
    }
}

Map::~Map()
{
    if(sceneData != nullptr){
        delete sceneData;
    }
    sceneData = nullptr;
    delete spriteList;
    spriteList = nullptr;
}

bool Map::addGO(Character* go, sf::Vector3i vect){
    mapList[vect.x][vect.y][vect.z] = go;
    sf::Vector2f pos;
    pos.x = startCorner.x + vect.x*(spacing+1);
    pos.y = startCorner.y + vect.y*(spacing+1);

    go->getAnimatedSprite()->setPosition(pos); // Will need to add z buffer to sprite
    spriteList->push_back(go->getAnimatedSprite());

    return true;
}

bool Map::addGO(Character* go, sf::Vector2i vect){
    sf::Vector3i newVect;
    newVect.x = vect.x;
    newVect.y = vect.y;
    newVect.z = 0;
    return addGO(go, newVect);
}

Character* Map::getGO(sf::Vector3f vect){
    sf::Vector3f ve = sf::Vector3f();
    ve.x = (int)vect.x;
    ve.y = (int)vect.y;
    ve.z = (int)vect.z;

    return getGO(ve);
}

Character* Map::getGO(sf::Vector3i vect){
    // Check if given vector is within map range.
    if(vect.x < 0 ||  vect.x > mSize.x ||
       vect.y < 0 || vect.y > mSize.y ||
       vect.z < 0 || vect.z > mSize.z)
    {
        return nullptr;
    }
    return mapList[vect.x][vect.y][vect.z];
}

bool Map::removeGO(Character& go){
    return true; // Add iterators here to go through and find object?
}

void Map::setMapPosition(sf::Vector3f startCorner, sf::Vector3f endCorner){
    setPlayPosition(startCorner, endCorner);
    setRenderPosition(startCorner);
}

void Map::setPlayPosition(sf::Vector3f startCorner, sf::Vector3f endCorner){
    // Notice how the more GO, the longer it takes. Try not to move board position dynamically. Use in-game effects for effects.
    for(int x=0; x < spriteList->size(); x++){
        sf::Vector2f pos = (*spriteList)[x]->getPosition();
        float locx = pos.x - this->startCorner.x;
        float locy = pos.y - this->startCorner.y;
        (*spriteList)[x]->setPosition(sf::Vector2f(locx + startCorner.x, locy + startCorner.y));
    }

    this->startCorner = startCorner;
    this->endCorner = endCorner;
}

void Map::setRenderPosition(sf::Vector3f pos){
    sceneData->getScene()->setPosition(sf::Vector2f(pos.x,pos.y)); //Will need to add z buffer sprite
    mapPos = pos;
}

void Map::setSpacing(int spc){
    spacing = spc;
}

bool Map::setScene(sf::Texture& tex){
    // Should TDScene delete animation? Yes.
    Animation* main = new Animation();
    main->setSpriteSheet(tex);
    sf::Vector2u siz = tex.getSize();
    main->addFrame(sf::IntRect(0,0,siz.x,siz.y));
    TDScene* tdScene = new TDScene();
    tdScene->setAnimation(main);
    sceneData = tdScene;
    return true;
}


 std::vector<AnimatedSprite*>* Map::getSpriteRender(){
    return spriteList;
}

Scene<AnimatedSprite*>* Map::getBackground(){
    return sceneData;
}

sf::Vector3f Map::getMapPos(){
    return mapPos;
}
