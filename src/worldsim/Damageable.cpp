#include "worldsim/Damageable.h"
namespace game {
    Damageable::Damageable()
    : health(common::Attribute<float>(1.f))
    {
        ;
    }

    void Damageable::applyDamage(const DamageDescriptor& damage)
    {
        health -= damage.getDamageSent();
    }
}