#ifndef UNITSTATE_H
#define UNITSTATE_H

#include <vector>

#include "common/LimitedValue.h"
#include "Attribute.h"

/*
    This class holds information about the state of a unit,
    in the context of a combat situation. It holds a set of LimitedFloats
    for basic attributes and a set of Modifiers for simple access
    to both the base attributes and the modified ones.
*/

namespace game {
    typedef unsigned int uint;
    typedef common::LimitedValue<float> LimitedFloat;

    class UnitState
    {
    public:
        UnitState();
        
    private:
        Attribute<float> unitAttributes[static_cast<uint>(AttributeType::NUM_ATTRIBUTES)];
    };
}

#endif