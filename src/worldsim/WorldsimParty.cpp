#include "worldsim/WorldsimParty.h"

namespace game {
    void WorldsimParty::addAttributeModifier(const Attributes& attrType, const AttributeModifier<float>& mod)
    {
        attributes.addAttributeModifier(attrType, mod);
        update();
    }

    void WorldsimParty::addAttributeModifierToCharacter(std::string name, const Attributes& attrType, const AttributeModifier<float>& mod)
    {
        getCharacter(name).addAttributeModifier(static_cast<WorldsimCharacter::Attributes>(attrType), mod);
        update();
    }

    void WorldsimParty::addCharacter(const WorldsimCharacter& character)
    {
        characters.push_back(character);
        update();
    }

    float WorldsimParty::getAttributeValue(const Attributes& attrType) const
    {
        return attributes.getAttributeValue(attrType);
    }

    WorldsimCharacter& WorldsimParty::getCharacter(std::string name)
    {
        for (auto& c : characters)
        {
            if (c.getName() == name)
            {
                return c;
            }
        }

        return characters[0];
    }

    void WorldsimParty::update()
    {
        float attributeValues[static_cast<unsigned int>(Attributes::NUM_ATTRIBUTES)] = {0.f};
        for (auto c : characters)
        {
            for (unsigned int i = 0; i < WorldsimCharacter::Attributes::NUM_ATTRIBUTES; i++)
            {
                attributeValues[i] += c.getAttribute(static_cast<WorldsimCharacter::Attributes>(i));
            }
        }

        for (unsigned int i = 0; i < WorldsimCharacter::Attributes::NUM_ATTRIBUTES; i++)
        {
            attributes.setAttributeBaseValue(static_cast<Attributes>(i), attributeValues[i]);
        }
    }
}