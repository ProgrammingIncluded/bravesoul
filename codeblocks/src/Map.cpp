#include "Map.h"
#include <memory>

Map::Map()
{
    startCorner = sf::Vector3f(0,0,0);
    mapPos = startCorner;
    endCorner = sf::Vector3f(1,1,0);
    int n = 10; // Note: n^3 Please be mindful... Might switch to array?
    mapList.resize(n);
    for(int i = 0; i < n; i++){
        mapList[i].resize(n);

        for(int x=0; x < n; x++ ){
            mapList[i][x].resize(n);
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

bool Map::addGO(GameObject* go, sf::Vector3f vect){
    mapList[vect.x][vect.y][vect.z] = go;
    go->setPosition(vect);
    go->getAnimatedSprite()->setPosition(sf::Vector2f(startCorner.x+vect.x,startCorner.y+vect.y)); // Will need to add z buffer to sprite
    spriteList.push_back(go->getAnimatedSprite());
    return true;
}

bool Map::addGO(GameObject* go, sf::Vector2f vect){
    mapList[0][0][0] = go; // Will need to fix for later
    go->setPosition(vect);
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
    this->startCorner = startCorner;
    this->endCorner = endCorner;

    // Notice how the more GO, the longer it takes. Try not to move board position dynamically. Use in-game effects for effects.
    for(int x=0; x < spriteList.size(); x++){
        sf::Vector3f vect = mapList[0][0][0]->getPosition();
        spriteList[x]->setPosition(sf::Vector2f(startCorner.x+vect.x, startCorner.y+vect.y));
    }
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
