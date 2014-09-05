#ifndef FIELD_H
#define FIELD_H

class Character;

#include "Attack.h"
#include "AttackD.h"
#include "Cursor.h"
#include "Map.h"

class Field
{
    public:
        // Make it so that map does not need to be set. Can be empty field. So that
        // sudden map changes can be made. Create addMap func.
        Field(Map* lvl);
        virtual ~Field();

        // Perform an attack based on object positions. This is faster
        // as player input selects coordinates. Names require searches.
        // Perhaps implement names only for AI and search based queries.
        // Add to Map?
        bool attack(sf::Vector3i atkr, sf::Vector3i rec, Attack atk);
        bool addChar(Character::charPtr ch, sf::Vector3i loc);

        // Custom function for custom checks on death or deletion of character. Will implement once attack system is working.
        //bool isDead(Character*)

        // bool addMap(); Used for sudden map changes or map interaction?

    private:
        // Decided to be passed via constructor.
        Map* level;

    protected:
};

#endif // FIELD_H
