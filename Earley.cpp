#include "Earley.h"



Earley::Earley(ContextFreeGrammar) {


}
bool Earley::InGrammar(const std::string &word) {
  return false;
}

bool Earley::Situation::operator<(const Earley::Situation &another) const {
  return false;
}
