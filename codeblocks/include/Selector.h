#ifndef SELECTOR_H
#define SELECTOR_H

#include <SFML/Graphics.hpp>

class Selector
{
    public:
        Selector();
        virtual ~Selector();

        bool setPosition();

    protected:

    private:
        sf::Vector3f position; // Center of box.
        sf::Vector3f sizeOfCursor; // Size relative to center of box.
};

#endif // SELECTOR_H
