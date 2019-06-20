#include "test.cpp"
#include "gtest/gtest.h"

TEST(BasicTests, AdditionTest){
  EXPECT_EQ(4, add(2, 2));
}

int main(void){
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}