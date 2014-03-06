#include "Map.h"
#include <iostream>


Map::Map(sf::Vector3i mSize)
{
    // Size allocation is based on dimensions.
    startCorner = sf::Vector3f(0,0,0);
    mapPos = startCorner;
    endCorner = sf::Vector3f(1,1,0);
    mSize.x += 1;
    mSize.y += 1;
    mSize.z += 1;
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
}

bool Map::addGO(GameObject* go, sf::Vector3i vect){
    mapList[vect.x][vect.y][vect.z] = go;
    //go->setPosition(vect);
    go->getAnimatedSprite()->setPosition(sf::Vector2f(startCorner.x+vect.x,startCorner.y+vect.y)); // Will need to add z buffer to sprite
    spriteList.push_back(go->getAnimatedSprite());
    return true;
}

bool Map::addGO(GameObject* go, sf::Vector2i vect){
    mapList[vect.x][vect.y][0] = go; // Will need to fix for later. What happens if object is there. Need to do that.
    //go->setPosition(vect);
    go->getAnimatedSprite()->setPosition(sf::Vector2f(startCorner.x+vect.x,startCorner.y+vect.y)); // Change source to accept vector2f
    spriteList.push_back(go->getAnimatedSprite());
    return true;
}

bool Map::removeGO(GameObject& go){
    return true; // Add iterators here to go through and find object?
}


void Map::setMapPosition(sf::Vector3f startCorner, sf::Vector3f endCorner){
    setPlayPosition(startCorner, endCorner);
    setRenderPosition(startCorner);
}

void Map::setPlayPosition(sf::Vector3f startCorner, sf::Vector3f endCorner){
    // Notice how the more GO, the longer it takes. Try not to move board position dynamically. Use in-game effects for effects.
    for(int x=0; x < spriteList.size(); x++){
        sf::Vector2f pos = spriteList[x]->getPosition();
        float locx = pos.x - this->startCorner.x;
        float locy = pos.y - this->startCorner.y;
        spriteList[x]->setPosition(sf::Vector2f(locx + startCorner.x, locy + startCorner.y));
    }

    this->startCorner = startCorner;
    this->endCorner = endCorner;
}

void Map::setRenderPosition(sf::Vector3f pos){
    sceneData->getScene()->setPosition(sf::Vector2f(pos.x,pos.y)); //Will need to add z buffer sprite
    mapPos = pos;
}

bool Map::setScene(std::string fileLoc){
    //Temporarly create scene MEMORy LEAK, I NOES
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile("assets/general/logo.png"))
    {
        return false;
    }
    Animation* main = new Animation();
    main->setSpriteSheet(*texture);
    main->addFrame(sf::IntRect(0,0,149,120));
    TDScene* tdScene = new TDScene();
    tdScene->setAnimation(main);
    sceneData = tdScene;
    return true;
}


 std::vector<AnimatedSprite*> Map::getSpriteRender(){
    return spriteList;
}

Scene<AnimatedSprite*>* Map::getBackground(){
    return sceneData;
}

sf::Vector3f Map::getMapPos(){
    return mapPos;
}
