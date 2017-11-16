#include "WorldsimCharacter.h"

namespace game {
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