#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
#include "Vector3iCompare.h"
#include "Character.h"
#include "Scene.h"
#include "TDScene.h"
#include "AnimatedSprite.h"

// Class for handling and creating the play area.
// Most parameters for Vector2f require map coordinates with top left
// corner being 0,0.  Not global coordinates unless otherwise noted.

class Map
{
    public:
        Map(sf::Vector3i mSize);
        virtual ~Map();

        // Add game object based on map coordinate no global.
        bool addGO(Character::charPtr go, sf::Vector3i vect); // Currently not used much.
        bool addGO(Character::charPtr go, sf::Vector2i vect); // For convenience...
        Character::charPtr getGO(sf::Vector3f vect);
        Character::charPtr getGO(sf::Vector3i vect);
        // Will need to implement via iteration.
        //bool removeGO(Character& go);

        // Delete character based on position in map.
        bool removeGO(sf::Vector3i pos);

        bool setScene(sf::Texture& tex);
        bool moveGO(std::string name, sf::Vector3f);

        //Sets grid positions.
        void setPlayPosition(sf::Vector3f startCorner, sf::Vector3f endCorner);
        void setRenderPosition(sf::Vector3f pos); //Note: only changes render area
        void setMapPosition(sf::Vector3f startCorner, sf::Vector3f endCorner);
        void setSpacing(int spc);

        // Given the map's coordinate system, returns a value for
        // the global SFML position.
        sf::Vector2f mapToGlobalPos(sf::Vector2f vect);

        std::map<sf::Vector3i,AnimatedSprite*, Vector3iCompare>* getSpriteRender(); // Temporary place holder, used for render handler
        Scene<AnimatedSprite*>* getBackground();
        sf::Vector3f getMapPos();
        //GLFloat get3DRender();

    private:
        std::vector<std::vector<std::vector<Character::charPtr>>> mapList;
        // Old trade off between performance and memory. Using memory as large maps would be very hard to get animated sprites every loop.
        // Change to smart pointers?
        std::map<sf::Vector3i,AnimatedSprite*, Vector3iCompare>* spriteList; // Used for organizing sprites
        // Smart pointers?
        Scene<AnimatedSprite*>* sceneData;
        sf::Vector3f startCorner; //Relative to scene. Scene renders at 0,0,0. Used for Character
        sf::Vector3f endCorner;
        sf::Vector3f mapPos; // Used for background location
        // Used for size of vector container. Deals with memory management.
        // Change so that check is from start and end corners.
        sf::Vector3i mSize;
        int spacing; // Spacing used for map

        // Function to check if given vector coordinates exist in size of map.
        bool inMap(sf::Vector3i vect);
};

#endif // MAP_H
