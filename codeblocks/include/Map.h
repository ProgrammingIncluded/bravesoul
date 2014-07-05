#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Character.h"
#include "Scene.h"
#include "TDScene.h"
#include "AnimatedSprite.h"

class Map
{
    public:
        Map(sf::Vector3i mSize);
        virtual ~Map();

        bool addGO(Character* go, sf::Vector3i vect);
        bool addGO(Character* go, sf::Vector2i vect); // For convenience...
        Character* getGO(sf::Vector3f vect);
        Character* getGO(sf::Vector3i vect);
        bool removeGO(Character& go);

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
        std::vector<std::vector<std::vector<Character*>>> mapList;
        std::vector<AnimatedSprite*>* spriteList; // Used for organizing sprites
        Scene<AnimatedSprite*> * sceneData;
        sf::Vector3f startCorner; //Relative to scene. Scene renders at 0,0,0. Used for Character
        sf::Vector3f endCorner;
        sf::Vector3f mapPos; // Used for background location
        sf::Vector3i mSize;
        int spacing; // Spacing used for map
};

#endif // MAP_H
