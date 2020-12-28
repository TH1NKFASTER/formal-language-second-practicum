#include "Earley.h"
#include <gtest/gtest.h>

TEST(FIRST, INCORRECT) {
  bool answer = false;
  EXPECT_EQ(answer, false);
}

TEST(SECOND, CORRECT) {
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar("");
  EXPECT_EQ(answer, true);
}

TEST(THIRD, CORRECT) {
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar("ab");
  EXPECT_EQ(answer, true);
}

TEST(FOURTH, CORRECT) {
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar("abab");
  EXPECT_EQ(answer, true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}