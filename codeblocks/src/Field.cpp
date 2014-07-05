#include "Field.h"

Field::Field(Map* lvl)
{
    // Fix after addMap is implemented
    if(lvl == nullptr)
    {

    }
    level = lvl;
}

Field::~Field()
{
    //dtor
}

bool Field::addChar(Character* ch, sf::Vector3i loc)
{
    if(ch == nullptr)
    {
        return false;
    }
    level->addGO(ch, loc);
    return true;
}

bool Field::attack(sf::Vector3i atker, sf::Vector3i rec, Attack atk)
{
    if(level->getGO(atker) == nullptr || level->getGO(rec) == nullptr) //Add return nullptr in map and check here.
    {
        std::cout << "It works!1" << std::endl;
    }
    else
    {
        std::cout << "It works!2" << std::endl;
    }
}
