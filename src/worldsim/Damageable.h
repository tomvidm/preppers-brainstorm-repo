#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "common/AttributeIncludes.h"
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
        inline common::Attribute<float> getHealth() const { return health; }
        virtual void applyDamage(const DamageDescriptor& damage);
    protected:
        common::Attribute<float> health;
    };
}

#endif