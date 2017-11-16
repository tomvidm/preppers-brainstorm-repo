#include "WorldsimCharacter.h"

namespace game {
    WorldsimCharacter::WorldsimCharacter(std::string name)
    : name_(name)
    {
        ;
    }

    void WorldsimCharacter::addAttributeModifier(const Attributes& attrType, const AttributeModifier<float>& mod)
    {
        attributes.addAttributeModifier(attrType, mod);
    }

    void WorldsimCharacter::setAttribute(const Attributes& attrType,
                                         const Attribute<float>& attr)
    {
        attributes.setAttribute(attrType, attr);
    }

    float WorldsimCharacter::getAttribute(const Attributes& attrType) const
    {
        return attributes.getAttributeValue(attrType);
    }
}