#ifndef SCENE_H
#define SCENE_H

enum tile_prop{
    water,
    lava,
    ice,
    fire,
    elec,
    rain
};

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "AnimatedSprite.h"

template<typename data> class Scene
{
    public:
        Scene(data d);
        virtual ~Scene();

        data& getScene();
        bool setScene(data d);

        bool setFileTileProp(std::string prop);
        bool setTileProp(sf::Vector3f v, tile_prop p);
        tile_prop getProperties(sf::Vector3f v);

    protected:
        data d;
        std::vector<std::vector<std::vector<tile_prop>>>tileProperties;

};


#endif // SCENE_H
