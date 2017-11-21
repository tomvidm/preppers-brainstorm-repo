#include "gtest/gtest.h"

#include "common/ObjectPool.h"

namespace common {
    TEST(TestObjectPool, AddAndRemoveObject)
    {
        common::ObjectPool<int> objPool;
        int newObj = objPool.addObject();
        EXPECT_EQ(objPool.getNumAllocatedSlots(), 1);
    }
}