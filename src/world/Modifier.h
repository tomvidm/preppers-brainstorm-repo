#ifndef COMBATCARD_H
#define COMBATCARD_H

#include <vector>

#include "Attributes.h"

/*
    Instead of polluting UnitState class with if-checks and
    such when adding +25% to organization or whatever, this class
    makes it easy to just pass a value and return the modified value,
    depending on what it should do.

    in object oriented programming, if it can be made an object, MAKE IT AN OBJECT.
    Everything becomes easier to maintain.
*/

namespace game {    
    typedef unsigned int uint;

    enum ModifierTarget {
        Attacker,
        Defender
    };

    enum ModifierEquation {
        AddFlat,        // targetAttribute + v
        MultiplyAndAdd, // targetAttribute * (1 + v);
        Multiply        // targetAttribute * v
    };

    class Modifier {
    public:
        Modifier(const AttributeType& attribute,
                 const ModifierTarget& target,
                 const ModifierEquation& equation,
                 const float& factor);
        inline AttributeType getAttribute() const { return attribute; }
        inline ModifierTarget getModifierTarget() const { return target; }
        inline ModifierEquation getModifierEquation() const { return equation; }
        inline float getFactor() const { return factor; }

        float modify(const float& value) const;
    private:
        AttributeType attribute;
        ModifierTarget target;
        ModifierEquation equation;
        float factor;
    };
}

#endif