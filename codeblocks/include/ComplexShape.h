#ifndef COMPLEXSHAPE_H
#define COMPLEXSHAPE_H


// Simple class to allow rendering of complex shapes.
// In other words, class for grouping multiple shapes togather
// that form one distinguishable/usable shape.
// Used by RenderHandler in order to create shapes not
// available by one shape class. Just one function :P...
// No C++ file

class ComplexShape
{
    public:
        // Using shapes as it is much more versatile.
        virtual const std::vector<sf::Shape*>& getShape() = 0;
        // Much like the function for convex Shapes,
        // Updates data/points whenever complex shape
        // is modified.
        // Should it be private?
        virtual void update() = 0;
};

#endif // COMPLEXSHAPE_H
