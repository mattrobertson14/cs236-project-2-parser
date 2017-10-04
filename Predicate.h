#pragma once
#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate {
public:
  Predicate();
  Predicate(string str);
  ~Predicate();

  void addParameterToList(Parameter par);
  string toString();

private:
  string id;
  vector<Parameter> parameter_list;
};
