#ifndef UNITSTATE_H
#define UNITSTATE_H

#include <vector>

#include "Attribute.h"

namespace game {
    typedef unsigned int uint;

    class UnitState
    {
    public:
        UnitState();
        
        void setAttribute(const AttributeType& attrType, const Attribute<float>& attr);
        Attribute<float>& getAttribute(const AttributeType& attrType);
        float getAttributeValue(const AttributeType& attrType) const;
    private:
        Attribute<float> unitAttributes[static_cast<uint>(AttributeType::NUM_ATTRIBUTES)];
    };
}

#endif