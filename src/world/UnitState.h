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
        void setAttribute(const AttributeType& attribute, const float& val);
        float getAttribute(const AttributeType& attribute) const;
        float getAttributeMax(const AttributeType& attribute) const;
    private:
        LimitedFloat attributes[static_cast<uint>(AttributeType::NUM_ATTRIBUTES)];
    };
}

#endif