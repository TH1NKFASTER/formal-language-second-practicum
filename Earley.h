#include <utility>

#include "ContextFreeGrammar.h"

class Earley {
 public:
  explicit Earley(ContextFreeGrammar);
  bool InGrammar(const std::string &word);
 private:

  class Situation {
   public:
    Situation(ContextFreeGrammar::Rule rule, size_t point, size_t i) : rule(std::move(rule)), point(point), i(i) {};
    bool operator<(const Situation &another) const;

    ContextFreeGrammar::Rule rule;

    size_t i;

    size_t point;
  };
};
