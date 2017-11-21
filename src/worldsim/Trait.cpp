#include "worldsim/Trait.h"

namespace game {
    Trait::Trait(String id)
    : name(id)
    {
        ;
    }
    
    float Trait::getOpinionModifierFor(String id) const
    {
        if (hasOpinionOf(id))
        {
            return map.get(id);
        }
        else
        {
            return 0;
        }
    }

    bool Trait::hasOpinionOf(String id) const
    {
        if (map.contains(id))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    float Trait::getOpinionOf(const std::vector<Trait>& traits) const
    {
        float result = 0.f;

        for (auto& trait : traits)
        {
            result += getOpinionModifierFor(trait.getName());
        }

        return result;
    }

    void Trait::setOpinionOf(String id, float opinion)
    {
        map.set(id, opinion);
    }
}