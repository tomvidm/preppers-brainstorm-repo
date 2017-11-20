#ifndef ATTRIBUTEARRAY_H
#define ATTRIBUTEARRAY_H

#include <vector>

#include "common/Attribute.h"

namespace common {
    enum ExampleAttributes
    {
        Attr1,
        Attr2,
        Attr3,
        NUM_ATTRIBUTES
    };

    template <typename T, typename E>
    class AttributeArray
    {
    public:
        void setAttribute(const E& attrType, const Attribute<T>& attr);
        Attribute<T>& getAttribute(const E& attrType);

    private:
        Attribute<T> attributes_[E::NUM_ATTRIBUTES];
    };

    template <typename T, typename E>
    void AttributeArray<T, E>::setAttribute(const E& attrType, const Attribute<T>& attr)
    {
        attributes_[static_cast<unsigned>(attrType)] = attr;
    }

    template <typename T, typename E>
    Attribute<T>& AttributeArray<T, E>::getAttribute(const E& attrType)
    {
        return attributes_[static_cast<unsigned>(attrType)];
    }
}

#endif