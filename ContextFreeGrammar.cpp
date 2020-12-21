#include "ContextFreeGrammar.h"

std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar) {
  return in;
}

bool ContextFreeGrammar::GoodRule(std::pair<char, std::string>) {
  return false;
}

ContextFreeGrammar::ContextFreeGrammar(const std::vector<std::string> &rules) {

}
