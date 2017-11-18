#include "gtest/gtest.h"

#include "worldsim/Attributes.h"
#include "worldsim/DamageDescriptor.h"
#include "worldsim/Body.h"

TEST(TestBody, RandomlyHitBodyParts)
{
    // Init body and a damage descriptor
    game::Body body;
    game::DamageDescriptor dmg(game::DamageType::Blunt, 0.f);

    // Store number of hits to each body part
    int hist[8] = {0};

    // FIRE!!!!!!! Fire blunt damage ha ha he he
    for (int i = 0; i < 1000; i++)
    {
        game::Part hitPart = body.receiveDamage(dmg);
        hist[static_cast<int>(hitPart)]++;
    }

    // Confirm that the head is hit less than the torso.
    EXPECT_TRUE(hist[0] < hist[1]);
}