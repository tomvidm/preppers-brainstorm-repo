#ifndef ACTOR_H
#define ACTOR_H

#include "common/AttributeMap.h"

namespace game {
    typedef common::Attribute<float> FloatAttribute;
    typedef common::AttributeMap<float> Attributes;

    class Actor
    {
    public:
        Actor();

        void setAttribute(const std::string& id, const FloatAttribute& attr);
        void setAttribute(const std::string& id, const float& value);
        FloatAttribute& getAttribute(const std::string& id);
        Attributes& getAttributes();
    private:
        Attributes attributes_;
    };
}

#endif