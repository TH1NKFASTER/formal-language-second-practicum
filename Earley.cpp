#include "Earley.h"

Earley::Earley(ContextFreeGrammar) {

}
bool Earley::InGrammar(const std::string &word) {
  return false;
}

bool operator<(const Earley::Situation &a, const Earley::Situation &b) {
  return false;
}
void Earley::Predict(size_t number) {

}
void Earley::Scan(size_t number, char symbol) {

}
void Earley::Complete(size_t number) {

}