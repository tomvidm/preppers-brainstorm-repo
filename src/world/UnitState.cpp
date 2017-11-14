#include "UnitState.h"

namespace game {
    void UnitState::setAttribute(const AttributeType& attribute, const float& val)
    {
        attributes[static_cast<uint>(attribute)] = val;
    }

    float UnitState::getAttribute(const AttributeType& attribute) const
    {
        return attributes[static_cast<uint>(attribute)].getValue();
    }

    float UnitState::getAttributeMax(const AttributeType& attribute) const
    {
        return attributes[static_cast<uint>(attribute)].getMax();
    }
}