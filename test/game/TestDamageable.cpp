#include "gtest/gtest.h"

#include "worldsim/Damageable.h"
#include "worldsim/DamageDescriptor.h"

TEST(TestDamageable, RemoveHealth)
{
    using namespace game;
    Damageable target;
    DamageDescriptor dmg(DamageType::Ballistic, 0.2f);
    EXPECT_EQ(target.getHealth().getValue(), 1.f);
    target.applyDamage(dmg);
    EXPECT_EQ(target.getHealth().getValue(), 0.8f);
}