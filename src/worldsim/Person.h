#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

#include "common/Map.h"
#include "worldsim/Trait.h"

namespace game {

    typedef std::string String;

    struct Name
    {
        String firstName = "fname";
        String lastName = "lname";
    };

    class Person
    {
    public:
        inline Name& getName() { return name_; }
        inline std::vector<Trait>& getTraits() { return traits; }
        inline std::vector<Trait> getTraits() const { return traits; }

        float getOpinionOf(const Person& other) const;
        void addTrait(const Trait& trait);
    private:
        Name name_;

        std::vector<Trait> traits;
    };
}

#endif