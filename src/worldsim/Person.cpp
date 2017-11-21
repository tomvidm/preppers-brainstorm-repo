#include "worldsim/Person.h"

namespace game {
    float Person::getOpinionOf(const Person& other) const
    {
        float opinion = 0.f;

        for (auto& myTrait : traits)
        {
            opinion += myTrait.getOpinionOf(other.getTraits());
        }

        return opinion;
    }

    void Person::addTrait(const Trait& trait)
    {
        traits.push_back(trait);
    }
}