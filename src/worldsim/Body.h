#ifndef BODY_H
#define BODY_H

#include <vector>

#include "worldsim/BodyPart.h"

namespace game {
    class Body
    {
    public:
        enum Part {
            Head,
            Torso,
            LeftHand, Right Hand,
            LeftArm, RightArm,
            LeftLeg, RightLeg,
            NUM_BODY_PARTS
        };

    private:
        BodyPart bodyParts[Part::NUM_BODY_PARTS];
        int sizeFactors[Part::NUM_BODY_PARTS] = { 2, 5, 1, 1, 2, 2, 3, 3 };
    }
}

#endif