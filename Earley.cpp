#include "Earley.h"

Earley::Earley(ContextFreeGrammar grammar) : grammar_(grammar) {

}

bool Earley::InGrammar(std::string word) {
  D_states_ = {};
  D_states_.resize(word.size() + 1);
  D_states_[0].insert(Situation(grammar_.rules[0], 0, 0));

  size_t current_size = D_states_[0].size();
  Complete(0);
  Predict(0);

  while (D_states_[0].size() != current_size) {
    current_size = D_states_[0].size();
    Complete(0);
    Predict(0);
  }

  for (size_t i = 1; i <= word.size(); ++i) {
    Scan(i, word[i - 1]);
    current_size = D_states_[i].size();
    Complete(i);
    Predict(i);
    while (D_states_[i].size() != current_size) {
      current_size = D_states_[i].size();
      Complete(i);
      Predict(i);
    }
  }
  return D_states_[word.size()].count(Situation(grammar_.rules[0], 1, 0));
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
  for (auto &st : D_states_[number - 1]) {
    if (st.rule.expression[st.point] == symbol) {
      D_states_[number].emplace(st.rule, st.point + 1, st.i);
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
