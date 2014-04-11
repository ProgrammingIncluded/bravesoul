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
        Map(sf::Vector3i mSize);
        virtual ~Map();

        bool addGO(GameObject* go, sf::Vector3i vect);
        bool addGO(GameObject* go, sf::Vector2i vect); // For convenience...
        GameObject* getGO(sf::Vector3f vect);
        GameObject* getGO(sf::Vector3i vect,  sf::Vector2f viewCoord);
        bool removeGO(GameObject& go);

        bool setScene(sf::Texture& tex);
        bool moveGO(std::string name, sf::Vector3f);

        void setPlayPosition(sf::Vector3f startCorner, sf::Vector3f endCorner); //Sets grid positions.
        void setRenderPosition(sf::Vector3f pos); //Note: only changes render area
        void setMapPosition(sf::Vector3f startCorner, sf::Vector3f endCorner);
        void setSpacing(int spc);

        std::vector<AnimatedSprite*>* getSpriteRender(); // Temporary place holder, used for render handler
        Scene<AnimatedSprite*>* getBackground();
        sf::Vector3f getMapPos();
        //GLFloat get3DRender();

    private:
        std::vector<std::vector<std::vector<GameObject*>>> mapList;
        std::vector<AnimatedSprite*>* spriteList; // Used for organizing sprites
        Scene<AnimatedSprite*> * sceneData;
        sf::Vector3f startCorner; //Relative to scene. Scene renders at 0,0,0. Used for gameObject
        sf::Vector3f endCorner;
        sf::Vector3f mapPos; // Used for background location
        sf::Vector3i mSize;
        int spacing; // Spacing used for map
};

#endif // MAP_H
