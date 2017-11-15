#ifndef UNITSTATE_H
#define UNITSTATE_H

#include "common/LimitedValue.h"
#include "Attributes.h"

namespace game {
    typedef unsigned int uint;
    typedef common::LimitedValue<float> LimitedFloat;

    class UnitState
    {
    public:
        UnitState();
        void setAttribute(const AttributeType& attribute, const LimitedFloat& limval);
        LimitedFloat getAttribute(const AttributeType& attribute) const;
        LimitedFloat& getAttribute(const AttributeType& attribute);
        float getAttributeValue(const AttributeType& attribute) const;
    private:
        LimitedFloat unitAttributes[static_cast<uint>(AttributeType::NUM_ATTRIBUTES)];
    };
}

#endif