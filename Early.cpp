#include "Early.h"

class Early::ERROR : public std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "ERROR";
  }
};

Early::Early(ContextFreeGrammar) {


}
bool Early::InGrammar(const std::string &word) {
  return false;
}

bool Early::Situation::operator<(const Early::Situation &another) const {
  return false;
}
