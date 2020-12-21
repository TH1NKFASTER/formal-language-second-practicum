#include "ContextFreeGrammar.h"

class Early {
 public:
  explicit Early(ContextFreeGrammar);
  bool InGrammar(const std::string &word);
 private:
  class ERROR;
  class Situation {
   public:
    Situation(std::pair<char, std::string> rule, size_t point, size_t i)
        : rule_(std::move(rule)), point_(point), i_(i) {};
    bool operator<(const Situation &another) const;

    std::pair<char, std::string> rule_;

    size_t i_;

    size_t point_;
  };
};
