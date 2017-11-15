#include "UnitState.h"

namespace game {
    UnitState::UnitState()
    {
        getAttribute(AttributeType::SoftAttack).imitateUnsigned();
        getAttribute(AttributeType::SoftDefense).imitateUnsigned();
    }

    void UnitState::setAttribute(const AttributeType& attribute, const LimitedFloat& limval)
    {
        unitAttributes[static_cast<uint>(attribute)] = limval;
    }

    LimitedFloat UnitState::getAttribute(const AttributeType& attribute) const
    {
        return unitAttributes[static_cast<uint>(attribute)];
    }

    LimitedFloat& UnitState::getAttribute(const AttributeType& attribute)
    {
        return unitAttributes[static_cast<uint>(attribute)];
    }

    float UnitState::getAttributeValue(const AttributeType& attribute) const
    {
        return unitAttributes[static_cast<uint>(attribute)].getValue();
    }
}