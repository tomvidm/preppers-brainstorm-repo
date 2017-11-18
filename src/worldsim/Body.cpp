#include "worldsim/Body.h"

namespace game {

    Body::Body()
    {
        bodyParts.resize(static_cast<int>(Part::NUM_BODY_PARTS));   
        //sizeFactors.resize(static_cast<int>(Part::NUM_BODY_PARTS));
        sizeFactors = { 3, 7, 2, 2, 3, 3, 4, 4 };
    }

    Part Body::receiveDamage(const DamageDescriptor& dmg, const Part& targettedPart)
    {
        std::vector<int> weights = sizeFactors;
        switch (targettedPart)
        {
            case Part::Head:
                weights[Part::Head] *= 3;
                break;
            case Part::Torso:
                weights[Part::Torso] *= 3;
                break;
            case Part::LeftHand:
                weights[Part::LeftHand] *= 3;
                break;
            case Part::RightHand:
                weights[Part::RightHand] *= 3;
                break;
            case Part::LeftArm:
                weights[Part::LeftArm] *= 3;
                break;
            case Part::RightArm:
                weights[Part::RightArm] *= 3;
                break;
            case Part::LeftLeg:
                weights[Part::LeftLeg] *= 3;
                break;
            case Part::RightLeg:
                weights[Part::RightLeg] *= 3;
                break;
            default:
                break;
        }

        common::DiscreteDistribution pdf(weights);
        int hit = pdf.rand();
        bodyParts[hit].applyDamage(dmg);
        return static_cast<Part>(hit);
    }
}