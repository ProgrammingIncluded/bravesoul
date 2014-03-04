#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "GameObject.h"
#include "Scene.h"
#include "TDScene.h"
#include "AnimatedSprite.h"

class Map
{
    public:
        Map();
        virtual ~Map();

        bool addGO(GameObject* go, sf::Vector3f vect);
        bool addGO(GameObject* go, sf::Vector2f vect); // For convenience...
        bool removeGO(GameObject& go);

        bool setScene(std::string fileLoc);
        bool moveGO(std::string name, sf::Vector3f);

        void setPlayPosition(sf::Vector3f startCorner, sf::Vector3f endCorner); //Sets grid positions.
        void setRenderPosition(sf::Vector3f pos); //Note: only changes render area
        void setMapPosition(sf::Vector3f startCorner, sf::Vector3f endCorner);

        std::vector<AnimatedSprite*> getSpriteRender(); // Temporary place holder, used for render handler
        Scene<AnimatedSprite*>* getBackground();
        sf::Vector3f getMapPos();
        //GLFloat get3DRender();

    private:
        std::vector<std::vector<std::vector<GameObject*>>> mapList;
        std::vector<AnimatedSprite*> spriteList; // Used for organizing sprites
        Scene<AnimatedSprite*> * sceneData;
        sf::Vector3f startCorner; //Relative to scene. Scene renders at 0,0,0
        sf::Vector3f endCorner;
        sf::Vector3f mapPos;

};

#endif // MAP_H
