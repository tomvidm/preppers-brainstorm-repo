#include "TestUnitState.h"

namespace game {
    void TestUnitState::SetUp()
    {
        ;
    }

    TEST_F(TestUnitState, AttributeAssignment)
    {
        LimitedFloat limval(1.f, 0.f, 1.f);
        ustate.setAttribute(AttributeType::SoftAttack, limval);
        EXPECT_EQ(ustate.getAttribute(AttributeType::SoftAttack), limval);
        EXPECT_EQ(ustate.getAttributeValue(AttributeType::SoftAttack), limval.getValue());
    }
}