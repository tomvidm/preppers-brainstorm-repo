#include "DamageDescriptor.h"

namespace game {
    DamageDescriptor::DamageDescriptor(const DamageType& dmgType,
                                       const float& dmgSent,
                                       const float& armPent,
                                       const int& turnDuration,
                                       const bool& canDismember)
    : damageType_(dmgType), 
      damageSent_(dmgSent), 
      armorPenetration_(armPent),
      turnDuration_(turnDuration),
      canDismember_(canDismember), 
      isLingering_((turnDuration > 0) || turnDuration == -1)
    {
        ;
    }
}