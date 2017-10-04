#pragma once
#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;

class String : public Parameter {

public:
  String(string str);
  ~String();

  string getValue();
  string toString();

private:
  string value;
};
