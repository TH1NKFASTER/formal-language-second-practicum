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
  std::string expression{};
};

bool ContextFreeGrammar::CheckRule(const std::string &rule) {
  if (rule.size() <= 4 || rule.substr(1, 2) != "->" || !this->non_terminals_.count(rule[0])) {
    throw ContextFreeGrammar::ERROR();
  }
  std::string expression = rule.substr(3);
  bool good = true;
  for (const auto &c : expression) {
    if (!this->terminals_.count(c)) {
      good = false;
      break;
    }
  }
  return good;
}

std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar) {
  size_t number_of_rules;
  in >> number_of_rules;
  grammar.rules = {ContextFreeGrammar::Rule('$', "S")};
  for (size_t i = 0; i < number_of_rules; ++i) {
    std::string rule;
    in >> rule;

    if (grammar.CheckRule(rule)) {
      grammar.rules.emplace_back(rule[0], rule.substr(3));
    } else {
      throw ContextFreeGrammar::ERROR();
    }

  }
  return in;
}

ContextFreeGrammar::ContextFreeGrammar(const std::vector<std::string> &vector_rules) {
  rules = {Rule('$', "S")};
  for (auto &rule: vector_rules) {
    if (CheckRule(rule)) {
      rules.emplace_back(rule[0], rule.substr(3));
    } else {
      throw ContextFreeGrammar::ERROR();
    }
  }
}
