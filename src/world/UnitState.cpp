#include "UnitState.h"

namespace game {
    UnitState::UnitState()
    {
        ;
    }

    void UnitState::setAttribute(const AttributeType& attrType, const Attribute<float>& attr)
    {
        unitAttributes[static_cast<uint>(attrType)] = attr;
    }

    Attribute<float>& UnitState::getAttribute(const AttributeType& attrType)
    {
        return unitAttributes[static_cast<uint>(attrType)];
    }

    float UnitState::getAttributeValue(const AttributeType& attrType) const
    {
        return unitAttributes[static_cast<uint>(attrType)].getValue();
    }
}