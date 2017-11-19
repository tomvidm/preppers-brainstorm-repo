#include "BodyPart.h"
#include <iostream>
namespace game {
    BodyPart::BodyPart()
    {
        ;
    }

    BodyPart::BodyPart(const std::string& name, const int& size)
    : name_(name), sizeFactor_(size)
    {
        ;
    }

    void BodyPart::applyDamage(const DamageDescriptor& damage)
    {
        health -= damage.getDamageSent();
    }
}