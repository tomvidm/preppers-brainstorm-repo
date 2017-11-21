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
        T getValue(const std::string& id) const;
        T getMax(const std::string& id) const;
        Attribute<T> getAttribute(const std::string& id);
    };

    template <typename T>
    T AttributeMap<T>::getValue(const std::string& id) const
    {
        return get(id).getValue();
    }

    template <typename T>
    T AttributeMap<T>::getMax(const std::string& id) const
    {
        return get(id).getMaxValue();
    }

    template <typename T>
    Attribute<T> AttributeMap<T>::getAttribute(const std::string& id)
    {
        return get(id);
    }
}

#endif