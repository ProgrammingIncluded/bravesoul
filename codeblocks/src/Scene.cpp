#include "Scene.h"

template<typename data>
Scene<data> ::Scene(data d)
{
    setScene(d);
}

template<typename data>
Scene<data> ::~Scene()
{
    tileProperties.clear();
}

template<typename data>
data Scene<data> ::getScene()
{
    return d;
}

template<typename data>
bool Scene<data> ::setScene(data d)
{
    this->d = d;
    return true;
}

template<typename data>
bool Scene<data>::setFileTileProp(std::string prop){
    //Temp place holder

}

template<typename data>
bool Scene<data>::setTileProp(sf::Vector3f v, tile_prop p){
    tileProperties[v.x][v.y][v.z] = p;
}

template<typename data>
tile_prop Scene<data>::getProperties(sf::Vector3f vect){
    return tileProperties[vect.x][vect.y][vect.z];
}

/*Template type declarations*/
template class Scene<AnimatedSprite*>; // Required for compiler to work.
