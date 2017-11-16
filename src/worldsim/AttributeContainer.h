#ifndef ATTRIBUTECONTAINER_H
#define ATTRIBUTECONTAINER_H

#include <vector>

#include "Attribute.h"

namespace game {
    typedef unsigned int uint;

    template <typename E>
    class AttributeContainer
    {
    public:
        AttributeContainer();
        
        void setAttribute(const E& attrType, const Attribute<float>& attr);
        Attribute<float>& getAttribute(const E& attrType);
        float getAttributeValue(const E& attrType) const;
    private:
        Attribute<float> unitAttributes[static_cast<uint>(E::NUM_ATTRIBUTES)];
    };

    template <typename E>
    AttributeContainer<E>::AttributeContainer()
    {
        ;
    }

    template <typename E>
    void AttributeContainer<E>::setAttribute(const E& attrType, const Attribute<float>& attr)
    {
        unitAttributes[static_cast<uint>(attrType)] = attr;
    }

    template <typename E>
    Attribute<float>& AttributeContainer<E>::getAttribute(const E& attrType)
    {
        return unitAttributes[static_cast<uint>(attrType)];
    }

    template <typename E>
    float AttributeContainer<E>::getAttributeValue(const E& attrType) const
    {
        return unitAttributes[static_cast<uint>(attrType)].getValue();
    }
}

#endif