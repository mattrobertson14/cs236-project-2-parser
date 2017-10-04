#pragma once
#include <string>
#include <vector>
#include "Predicate.h"
#include "Parameter.h"

using namespace std;

class Rule {
public:
  Rule(Predicate head);
  ~Rule();

  void addPredicateToList(Predicate pred);
  void addParamToPred(Parameter par);
  string toString();

private:
  Predicate head_predicate;
  vector<Predicate> predicate_list;
};
