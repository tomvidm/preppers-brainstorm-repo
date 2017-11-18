#include "BodyPart.h"

namespace game {
    void BodyPart::applyDamage(const DamageDescriptor& damage)
    {
        if (damage.isLingering())
        {
            ;
        }
        else
        {
            health -= damage.getDamageSent();
        }
    }
}