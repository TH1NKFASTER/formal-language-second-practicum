#include "Earley.h"

Earley::Earley(ContextFreeGrammar grammar) : grammar_(grammar) {

}

bool Earley::InGrammar(const std::string &word) {
  return false;
}

bool operator<(const Earley::Situation &a, const Earley::Situation &b) {
  return a.rule < b.rule || a.rule == b.rule && a.point < b.point
      || a.rule == b.rule && a.point == b.point && a.i < b.i;
}

void Earley::Predict(size_t number) {

}

void Earley::Scan(size_t number, char symbol) {
  for (auto st : D_states_[number]) {
    if (st.rule.second[st.point_] == symbol) {
      D_states_[number + 1].emplace(st.rule, st.point + 1, st.i);
    }
  }
}

void Earley::Complete(size_t number) {

}
