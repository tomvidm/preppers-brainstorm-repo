#include "worldsim/Damageable.h"
namespace game {
    Damageable::Damageable()
    : health(Attribute<float>(1.f, 1.f))
    {
        ;
    }

    void Damageable::applyDamage(const DamageDescriptor& damage)
    {
        health -= damage.getDamageSent();
    }
}