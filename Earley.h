#include <utility>

#include "ContextFreeGrammar.h"

class Earley {
 public:
  explicit Earley(ContextFreeGrammar grammar);

  bool InGrammar(const std::string &word);

  class Situation {
   public:
    Situation(ContextFreeGrammar::Rule rule, size_t point, size_t i) : rule(std::move(rule)), point(point), i(i) {};

    friend bool operator<(const Situation &a, const Situation &b);

    ContextFreeGrammar::Rule rule;

    size_t i;

    size_t point;
  };
 private:
  void Predict(size_t number);
  void Scan(size_t number, char symbol);
  void Complete(size_t number);
  std::vector<std::set<Situation>> D_states_{};
  ContextFreeGrammar grammar_;
};
