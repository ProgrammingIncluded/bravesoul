#ifndef DAMAGE_H
#define DAMAGE_H

class Damage;

//! Damage class for Damage Packet.
/**
* Damage class that is used in DamagePacket.
* Values are subtractions by default, so positive = subtract.
* No getters and setters are created as this is created to function
* like a data type. Access members directly.
*
*/

class Damage
{
    public:
        Damage();

        //! Operator Overriding.
        friend Damage operator+(const Damage & a, const Damage & b);
        friend Damage operator-(const Damage & a, const Damage & b);
        friend Damage operator*(const Damage & a, const Damage & b);
        friend Damage operator/(const Damage & a, const Damage & b);

        int hp; /**< Stores subtractive Health Point.*/
        int mp; /**< Stores subtractive Magic Point.*/
        int stm; /**< Stores subtractive Stamina.*/

};

#endif // DAMAGE_H
