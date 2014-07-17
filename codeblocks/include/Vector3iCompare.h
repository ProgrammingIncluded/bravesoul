#ifndef VECTOR3ICOMPARE_H
#define VECTOR3ICOMPARE_H

#include <SFML/Graphics.hpp>

struct Vector3iCompare
{
   bool operator() (const sf::Vector3i& lhs, const sf::Vector3i& rhs);
};


#endif // VECTOR3ICOMPARE_H
