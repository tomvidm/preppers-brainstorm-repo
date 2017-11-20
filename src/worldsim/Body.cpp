#include "worldsim/Body.h"

#include <iostream>
#include <iomanip>

namespace game {

    Body::Body()
    {
        bodyParts.resize(static_cast<int>(Part::NUM_BODY_PARTS));   
        //sizeFactors.resize(static_cast<int>(Part::NUM_BODY_PARTS));
        sizeFactors = { 3, 7, 2, 2, 3, 3, 4, 4 };
        for (unsigned i = 0; i < sizeFactors.size(); i++)
        {
            bodyParts[i].setSizeFactor(sizeFactors[i]);
        }
        bodyParts[0].setName("Head");
        bodyParts[1].setName("Torso");
        bodyParts[2].setName("LeftHand");
        bodyParts[3].setName("RightHand");
        bodyParts[4].setName("LeftArm");
        bodyParts[5].setName("RightArm");
        bodyParts[6].setName("LeftLeg");
        bodyParts[7].setName("RightLeg");
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

    void Body::assessHealth() const
    {
        for (auto& bp : bodyParts)
        {
            common::Attribute<float> health = bp.getHealth();
            std::cout << std::setw(10) << bp.getName() << "  " << health.getValue() << "/" << health.getMaxValue() << std::endl;
        }
    }

    void Body::assessHitChances(const Part& aimedPart) const
    {
        std::vector<int> weights = sizeFactors;
        switch (aimedPart)
        {
            case Part::Head:
                weights[Part::Head] *= 5;
                break;
            case Part::Torso:
                weights[Part::Torso] *= 5;
                break;
            case Part::LeftHand:
                weights[Part::LeftHand] *= 5;
                break;
            case Part::RightHand:
                weights[Part::RightHand] *= 5;
                break;
            case Part::LeftArm:
                weights[Part::LeftArm] *= 5;
                break;
            case Part::RightArm:
                weights[Part::RightArm] *= 5;
                break;
            case Part::LeftLeg:
                weights[Part::LeftLeg] *= 5;
                break;
            case Part::RightLeg:
                weights[Part::RightLeg] *= 5;
                break;
            default:
                break;
        }
        common::DiscreteDistribution pdf(weights);
        std::vector<double> prob = pdf.getProbabilities();
        for (int i = 0; i < bodyParts.size(); i++)
        {
            std::cout << std::setw(10) << bodyParts[i].getName() << "  " << std::setprecision(2) << prob[i] << std::endl;
        }
    }
}