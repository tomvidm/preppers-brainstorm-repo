#ifndef BODYPART_H
#define BODYPART_H

#include "worldsim/Damageable.h"

namespace game {
    class BodyPart : public Damageable
    {
    public:
        BodyPart();
        BodyPart(const std::string& name, const int& size);
        virtual void applyDamage(const DamageDescriptor& damage);
        inline void setSizeFactor(const int& size) { sizeFactor_ = size; }
        inline void setName(const std::string& name) { name_ = name; }
        inline std::string getName() const { return name_; }
    protected:
        std::string name_;
        int sizeFactor_;
    };
}

#endif