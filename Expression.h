#pragma once
#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;

class Expression : public Parameter {

public:
  Expression(Parameter p1, Parameter p2, string oprtr);
  ~Expression();

  string toString();

private:
  Parameter parameter1;
  Parameter parameter2;
  string oper;
};
