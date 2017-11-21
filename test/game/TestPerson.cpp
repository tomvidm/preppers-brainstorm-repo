#include "gtest/gtest.h"

#include "worldsim/Person.h"
#include "worldsim/Trait.h"

namespace game {
    TEST(TestPerson, Opinions)
    {
        Person p1;
        Person p2;
        EXPECT_EQ(p1.getOpinionOf(p2), 0.f);

        Trait trait_nazi("nazi");
        Trait trait_black("black");
        Trait trait_jew("jew");

        trait_nazi.setOpinionOf("black", -50.f);
        trait_nazi.setOpinionOf("jew", -50.f);

        trait_black.setOpinionOf("hiphopfan", 20.f);
        trait_black.setOpinionOf("black", 10.f);
        trait_black.setOpinionOf("nazi", -20.f);

        trait_jew.setOpinionOf("nazi", -50.f);
        trait_jew.setOpinionOf("merchant", 100.f);

        p1.addTrait(trait_nazi);

        p2.addTrait(trait_jew);
        p2.addTrait(trait_black);

        EXPECT_EQ(p1.getOpinionOf(p2), -100.f);
    }
    
}