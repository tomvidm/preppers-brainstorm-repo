#ifndef WORLDSIMPARTY_H
#define WORLDSIMPARTY_H

#include <vector>

#include "worldsim/WorldsimCharacter.h"
#include "worldsim/AttributeContainer.h"

namespace game {

    enum Attributes {
        // Basic attributes
        SoftAttack,
        SoftDefense,
        HardAttack,
        HardDefense,
        Morale,
        Dicipline,
        Organization,
        Entrenchment,
        NUM_ATTRIBUTES
        };

    class WorldsimParty
    {
    public:
        void addAttributeModifier(const Attributes& attrType, const AttributeModifier<float>& mod);
        void addAttributeModifierToCharacter(std::string name, const Attributes& attrType, const AttributeModifier<float>& mod);
        float getAttributeValue(const Attributes& attrType) const;
        void addCharacter(const WorldsimCharacter& character);

        WorldsimCharacter& getCharacter(std::string name);
    private:
        void update();
        std::vector<WorldsimCharacter> characters;
        AttributeContainer<Attributes> attributes;
    };
}

#endif