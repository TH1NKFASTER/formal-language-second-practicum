#include <string>
#include <vector>
#include <set>
class ContextFreeGrammar {
 public:
  explicit ContextFreeGrammar(const std::vector<std::string> &rules);
  bool GoodRule(std::pair<char, std::string>);
  friend std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar);
  ContextFreeGrammar() = default;
 private:
  std::set<char> non_terminals_;
  std::set<char> alphabet_;
  std::vector<std::pair<char, std::string>> rules_;
};

