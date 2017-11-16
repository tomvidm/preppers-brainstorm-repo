#ifndef WORLDSIMCHARACTER_H
#define WORLDSIMCHARACTER_H

#include <string>

#include "worldsim/AttributeContainer.h"

namespace game {
    class WorldsimCharacter
    {
    public:
        enum Attributes {
        // Basic attributes
        SoftAttack,
        SoftDefense,
        HardAttack,
        HardDefense,
        Morale,
        Dicipline,
        NUM_ATTRIBUTES
    };
        WorldsimCharacter(std::string name);
        void addAttributeModifier(const Attributes& attrType, const AttributeModifier<float>& mod);
        void setAttribute(const Attributes& attrType, const Attribute<float>& attr);
        float getAttribute(const Attributes& attrType) const;

        inline std::string getName() const { return name_; }
    private:
        std::string name_;
        AttributeContainer<Attributes> attributes;
    };
}

#endif