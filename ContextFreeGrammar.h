#include <string>
#include <vector>
#include <set>
class ContextFreeGrammar {
 private:
  bool CheckRule(const std::string &rule);
  std::set<char> non_terminals_;
  std::set<char> terminals_;
 public:
  class ERROR;

  class Rule {
   public:
    Rule() = default;

    Rule(char non_terminal, std::string expression) : non_terminal(non_terminal), expression(std::move(expression)) {}

    char non_terminal{};

    std::string expression{};

    friend bool operator<(const Rule &a, const Rule &b) {
      return a.non_terminal < b.non_terminal || a.non_terminal == b.non_terminal && a.expression < b.expression;
    }

    friend bool operator==(const Rule &a, const Rule &b) {
      return a.non_terminal == b.non_terminal && a.expression == b.expression;
    }
  };

  explicit ContextFreeGrammar(const std::vector<std::string> &vector_rules);

  friend std::istream &operator>>(std::istream &in, ContextFreeGrammar &grammar);

  ContextFreeGrammar() = default;

  std::vector<Rule> rules;
};

