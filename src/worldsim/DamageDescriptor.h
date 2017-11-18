#ifndef DAMAGE_H
#define DAMAGE_H

#include "worldsim/Attributes.h"

namespace game {

    class DamageDescriptor
    {
    public:
        DamageDescriptor(const DamageType& dmgType,
                         const float& dmgSent,
                         const float& armPent = 0.f,
                         const int& turnDuration = -1,
                         const bool& canDismember = false);
        inline DamageType getDamageType() const { return damageType_; }
        inline float getDamageSent() const { return damageSent_; }
        inline float getArmorPenetration() const { return armorPenetration_; }
        inline int getTurnDuration() const { return turnDuration_; }
        inline bool isLingering() const { return isLingering_; }
        inline bool canDismember() const { return canDismember_; }

    private:
        const DamageType damageType_;
        const float damageSent_ = 0.f;
        const float armorPenetration_ = 0.f;
        const int turnDuration_ = -1;
        const bool canDismember_ = false;
        const bool isLingering_ = false;
    };
}

#endif