#include "worldsim/Damageable.h"

namespace game {
    Damageable::Damageable()
    : health(Attribute<float>(1.f, 1.f))
    {
        ;
    }

    float Damageable::getHealth() const
    {
        return health.getValue();
    }

    void Damageable::applyDamage(const DamageDescriptor& damage)
    {
        health -= damage.getDamageSent();
    }
}