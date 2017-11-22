#include "worldsim/Person.h"
#include <iostream>
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

    void Person::printTrait() const
    {
        for (auto& t : traits)
        {
            std::cout << t.getName() << " - " << t.getDescription() << std::endl;
        }
    }
}