#ifndef PERSONTRAITS_H
#define PERSONTRAITS_H

#include <map>
#include <string>
#include <vector>

namespace game {
    class Trait
    {
    public:
        inline std::string getName() const { return traitName_; }
        inline common::Attribute<float> getAttribute
    private:
        std::string traitName_;
        std::map<std::string, common::AttributeModifier<float>> traitModifiers;
    };

    class Personality
    {
    private:
        std::vector<Trait> traits;
    };
}

#endif