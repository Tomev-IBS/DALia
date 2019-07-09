//
// Created by Tomev on 09.07.2019.
// A class for classical inferer testing.
//

#include "gtest/gtest.h"
#include "inference/classicalInferer.h"

class classicalInfererTest : public ::testing::Test {
  public:
    DALia::classicalInferer inferer;
  protected:
    void SetUp() override {

    }
    void TearDown() override {}
};

TEST_F(classicalInfererTest, InferenceTypeCheck){
  ASSERT_EQ(inferer.getInferenceType(), "Classical Inference");
}

