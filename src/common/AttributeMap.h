#ifndef ATTRIBUTEMAP_H
#define ATTRIBUTEMAP_H

#include <string>
#include <map>

#include "common/Map.h"
#include "common/Attribute.h"

namespace common {
    template <typename T>
    class AttributeMap : public Map<Attribute<T>>
    {
    public:
        T getValue() const;
        T getMax() const;
    };

    template <typename T>
    T AttributeMap<T>::getValue() const
    {
        return get(id).getValue();
    }

    template <typename T>
    T AttributeMap<T>::getMax() const
    {
        return get(id).getMaxValue();
    }
}

#endif