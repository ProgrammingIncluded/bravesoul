#ifndef EFFECT_H
#define EFFECT_H

#include "GameObject.h"

class GameObject;

class Effect{
    public:
        //! Abstract Functions
        /*! Function called when effect wants to be applied. */
        virtual void affect(GameObject* go, int str) = 0; //Might change to overloading for character and weapon.

        //! Getters
        enum_effect getEName();

        //! Setters
        void setEName(enum_effect enm);

    private:
        /*! Stores associated enum with class. Used to define class name.*/
        enum_effect ename; //
};

#endif // EFFECT_H
