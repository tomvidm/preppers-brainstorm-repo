#ifndef BODYPART_H
#define BODYPART_H

#include "worldsim/Damageable.h"

namespace game {
    class BodyPart : public Damageable
    {
    public:
        virtual void applyDamage(const DamageDescriptor& damage);
        inline void setSizeFactor(const int& size) { sizeFactor_ = size; }
    protected:
        int sizeFactor_;
    };
}

#endif