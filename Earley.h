#include "ContextFreeGrammar.h"

class Earley {
 public:
  explicit Earley(ContextFreeGrammar);
  bool InGrammar(const std::string &word);
 private:

  class Situation {
   public:
    Situation(ContextFreeGrammar::Rule rule, size_t point, size_t i)
        : rule_(std::move(rule)), point_(point), i_(i) {};
    bool operator<(const Situation &another) const;

    std::pair<char, std::string> rule_;

    size_t i_;

    size_t point_;
  };
};
