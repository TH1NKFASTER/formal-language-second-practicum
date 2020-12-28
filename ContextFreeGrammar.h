#include <string>
#include <vector>
#include <set>
class ContextFreeGrammar {
 private:
  class ERROR;
  bool CheckRule(const std::string& rule);
  std::set<char> non_terminals_;
  std::set<char> terminals_;
 public:
  class Rule;
  explicit ContextFreeGrammar(const std::vector<std::string> &vector_rules);
  friend std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar);
  ContextFreeGrammar() = default;
  std::vector<Rule> rules;
};

