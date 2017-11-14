#ifndef COMBATCARD_H
#define COMBATCARD_H

#include <vector>

#include "Attributes.h"

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