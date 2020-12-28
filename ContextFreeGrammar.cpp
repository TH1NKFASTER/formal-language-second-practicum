#include "ContextFreeGrammar.h"
#include <iostream>
#include <utility>

class ContextFreeGrammar::ERROR : public std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "ERROR";
  }
};

class ContextFreeGrammar::Rule {
 public:
  Rule() = default;
  Rule(char non_terminal, std::string expression) : non_terminal(non_terminal), expression(std::move(expression)) {}
  char non_terminal{};
  std::string expression;
};

std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar) {
  size_t number_of_rules;
  in >> number_of_rules;
  grammar.rules = {ContextFreeGrammar::Rule('$', "S")};
  for (size_t i = 0; i < number_of_rules; ++i) {
    std::string rule;
    in >> rule;
    if (rule.size() <= 4 || rule.substr(1, 2) != "->" || !grammar.non_terminals_.count(rule[0])) {
      throw ContextFreeGrammar::ERROR();
    }
    char non_terminal = rule[0];
    std::string expression = rule.substr(3, rule.size() - 3);
    bool good = true;
    for (const auto &c : expression) {
      if (!grammar.terminals_.count(c)) {
        good = false;
        break;
      }
    }
    if (good) {
      grammar.rules.emplace_back(non_terminal, expression);
    } else {
      throw ContextFreeGrammar::ERROR();
    }

  }
  return in;
}

ContextFreeGrammar::ContextFreeGrammar(const std::vector<std::string> &rules) {

}
bool ContextFreeGrammar::GoodRule(ContextFreeGrammar::Rule rule) {
  return false;
}
