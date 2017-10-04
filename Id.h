#pragma once
#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;

class Id : public Parameter {

public:
  Id(string str);
  ~Id();

  string getValue();
  string toString();

private:
  string value;
};
