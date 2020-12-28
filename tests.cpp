#include "Earley.h"
#include <gtest/gtest.h>

TEST(FIRST, INCORRECT) {
  bool answer = false;
  EXPECT_EQ(answer, false);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}