#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "worldsim/Attribute.h"
#include "worldsim/DamageDescriptor.h"

/*
    Inherit from this class to make an object
    damageable.
*/

namespace game {
    class Damageable
    {
    public:
        Damageable();
        float getHealth() const;
        virtual void applyDamage(const DamageDescriptor& damage);
    protected:
        Attribute<float> health;
    };
}

#endif