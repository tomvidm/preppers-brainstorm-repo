#ifndef BODY_H
#define BODY_H

#include <vector>

#include "worldsim/BodyPart.h"
#include "common/DiscreteDistribution.h"

namespace game {

    enum Part {
        Head,
        Torso,
        LeftHand, RightHand,
        LeftArm, RightArm,
        LeftLeg, RightLeg,
        NUM_BODY_PARTS
    };

    class Body
    {
    public:
        Body();
        Part receiveDamage(const DamageDescriptor& dmg, const Part& targettedPart = Part::NUM_BODY_PARTS);
        void assessHealth() const;
        void assessHitChances(const Part& aimedPart = Part::NUM_BODY_PARTS) const;
        inline BodyPart getBodyPart(const Part& part) const { return bodyParts[static_cast<int>(part)]; }
    private:
        std::vector<BodyPart> bodyParts;
        std::vector<int> sizeFactors;
    };
}

#endif