#include <iostream>
#include "Earley.h"

int main() {
  ContextFreeGrammar grammar;
  std::string word;
  std::cin >> grammar >> word;
  try {
    std::cout << (Earley(grammar).InGrammar(word) ? "YES" : "NO") << std::endl;
  } catch (std::exception &exception) {
    std::cout << exception.what();
  }
}

