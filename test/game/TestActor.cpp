#include "gtest/gtest.h"

#include "worldsim/Actor.h"

namespace game {
    TEST(TestActor, AttributeAssignment)
    {
        Actor ac;
        EXPECT_EQ(ac.getAttribute("health").getValue(), 100.f);
        ac.setAttribute("health", 50.f);
        EXPECT_EQ(ac.getAttribute("health").getValue(), 50.f);
    }
}