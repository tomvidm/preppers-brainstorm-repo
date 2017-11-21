#include "worldsim/Actor.h"

namespace game {
    Actor::Actor()
    {
        attributes_.set("health", common::Attribute<float>(100.f));
    }

    void Actor::setAttribute(const std::string& id, const FloatAttribute& attr)
    {
        attributes_.set(id, attr);
    }

    void Actor::setAttribute(const std::string& id, const float& value)
    {
        setAttribute(id, FloatAttribute(value));
    }

    FloatAttribute& Actor::getAttribute(const std::string& id)
    {
        return attributes_.get(id);
    }

    Attributes& Actor::getAttributes()
    {
        return attributes_;
    }
}