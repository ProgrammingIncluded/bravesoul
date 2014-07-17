#include "Vector3iCompare.h"

bool Vector3iCompare::operator()(const sf::Vector3i& lhs, const sf::Vector3i& rhs)
{
    if(lhs.x != rhs.x)
    {
        return (lhs.x < rhs.x);
    }
    else if(lhs.y != rhs.y)
    {
        return (lhs.y < rhs.y);
    }

    return (lhs.z < rhs.z);
}
