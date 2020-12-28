#include <string>
#include <vector>
#include <set>
class ContextFreeGrammar {
 private:
  class ERROR;
  class Rule;
  bool GoodRule(Rule rule);
  std::set<char> non_terminals_;
  std::set<char> terminals_;
 public:
  explicit ContextFreeGrammar(const std::vector<std::string> &rules);
  friend std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar);
  ContextFreeGrammar() = default;
  std::vector<Rule> rules;
};

