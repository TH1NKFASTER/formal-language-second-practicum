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

TEST(FIFTH, INCORRECT) {
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar("ba");
  EXPECT_EQ(answer, false);
}

TEST(SIXTH, INCORRECT) {
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar("aba");
  EXPECT_EQ(answer, false);
}

TEST(SEVENTH, CORRECT) {
  std::string word;
  for (int i = 0; i < 1000; ++i) {
    word.push_back('a');
  }
  for (int i = 0; i < 1000; ++i) {
    word.push_back('b');
  }
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar(word);
  EXPECT_EQ(answer, true);
}

TEST(EIGTH, CORRECT) {
  std::string word;
  for (int i = 0; i < 1000; ++i) {
    word.push_back('a');
  }
  for (int i = 0; i < 1000; ++i) {
    word.push_back('b');
  }
  word[0] = 'b';
  auto brackets = ContextFreeGrammar({"S->", "S->SaSb"});
  bool answer = Earley(brackets).InGrammar(word);
  EXPECT_EQ(answer, false);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}