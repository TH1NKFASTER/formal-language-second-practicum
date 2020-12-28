#include "Earley.h"

Earley::Earley(ContextFreeGrammar grammar) : grammar_(grammar) {

}

bool Earley::InGrammar(std::string word) {
  return false;
}

bool operator<(const Earley::Situation &a, const Earley::Situation &b) {
  return a.rule < b.rule || a.rule == b.rule && a.point < b.point
      || a.rule == b.rule && a.point == b.point && a.i < b.i;
}

void Earley::Predict(size_t number) {
  for (auto &st : D_states_[number]) {
    for (auto &rule : grammar_.rules) {
      if (rule.non_terminal == st.rule.expression[st.point]) {
        D_states_[number].insert(Situation(rule, 0, number));
      }
    }
  }
}

void Earley::Scan(size_t number, char symbol) {
  if (number == 0) {
    return;
  }
  for (auto &st : D_states_[number]) {
    if (st.rule.expression[st.point] == symbol) {
      D_states_[number + 1].emplace(st.rule, st.point + 1, st.i);
    }
  }
}

void Earley::Complete(size_t number) {
  for (auto &st_num : D_states_[number]) {
    if (st_num.point == st_num.rule.expression.size()) {
      for (auto st_b : D_states_[st_num.i]) {
        if (st_b.rule.expression[st_b.point] == st_num.rule.non_terminal) {
          D_states_[number].insert(Situation(st_b.rule, st_b.point + 1, st_b.i));
        }
      }
    }
  }
}
