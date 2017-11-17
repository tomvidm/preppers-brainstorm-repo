#ifndef ATTRIBUTECONTAINER_H
#define ATTRIBUTECONTAINER_H

#include <vector>

#include "common/Logger.h"

#include "Attribute.h"

namespace game {
    typedef unsigned int uint;

    /*
        The AttributeContainer contains a number of "attributes",
        which are wrappers for values which may or may not have a
        maximum value.

        The requirements for E is
        * must be an enum
        * the enum values must start at 0
          and increase by one
        * the last enum value must have
          the name NUM_ATTRIBUTES
    */

    template <typename E>
    class AttributeContainer
    {
    public:
        AttributeContainer();
        
        void addAttributeModifier(const E& attrType, const AttributeModifier<float>& mod);
        void setAttribute(const E& attrType, const Attribute<float>& attr);
        void setAttributeBaseValue(const E& attrType, const float& val);
        Attribute<float>& getAttribute(const E& attrType);
        float getAttributeValue(const E& attrType) const;
        void onTurn();
    private:
        Attribute<float> attributes[static_cast<uint>(E::NUM_ATTRIBUTES)];
    };

    template <typename E>
    AttributeContainer<E>::AttributeContainer()
    {
        ;
    }

    template <typename E>
    void AttributeContainer<E>::addAttributeModifier(const E& attrType, const AttributeModifier<float>& mod)
    {
        attributes[static_cast<uint>(attrType)].addModifier(mod);
    }

    template <typename E>
    void AttributeContainer<E>::setAttribute(const E& attrType, const Attribute<float>& attr)
    {
        attributes[static_cast<uint>(attrType)] = attr;
    }

    template <typename E>
    void AttributeContainer<E>::setAttributeBaseValue(const E& attrType, const float& val)
    {
        attributes[static_cast<uint>(attrType)].setBaseValue(val);
    }

    template <typename E>
    Attribute<float>& AttributeContainer<E>::getAttribute(const E& attrType)
    {
        return attributes[static_cast<uint>(attrType)];
    }

    template <typename E>
    float AttributeContainer<E>::getAttributeValue(const E& attrType) const
    {
        return attributes[static_cast<uint>(attrType)].getValue();
    }

    template <typename E>
    void AttributeContainer<E>::onTurn()
    {
        for (auto& a : attributes)
        {
            a.onTurn();
        }
    }
}

#endif