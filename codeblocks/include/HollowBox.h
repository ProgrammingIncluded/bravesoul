#ifndef HOLLOWBOX_H
#define HOLLOWBOX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <ComplexShape.h>

// Class that draws Hollow Box. Cannot be a shape as
// Shape is not concavable.

// Needs to extend shape

class HollowBox : public ComplexShape
{
    public:
        HollowBox(const sf::Vector2f& sizeVect = sf::Vector2f(1,1));
        virtual ~HollowBox();

        // Add set size function...

        // Remove once implement drawable.
        const std::vector<sf::Shape*>& getShape();
        void update();
        void setPosition(sf::Vector2f vect);
        sf::Vector2f getPosition();

        // Getters and Setters
        bool setThickness(float thick);
        float getThickness();

        bool setSize(const sf::Vector2f& sizeHB);
        // Risky but less costly... Not going to be too malicious.
        const sf::Vector2f& getSize();

    private:
        sf::Vector2f sizeB;
        // Thickness of border.
        float thickness;

        // Pointer for dynamic allocation usage,
        // since possible multiple files.
        // Holds complex shapes.
        std::vector<sf::Shape*>* polygon;
};

#endif // HOLLOWBOX_H
