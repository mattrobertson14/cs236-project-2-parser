#include <string>
#include <vector>
#include "Expression.h"

using namespace std;

Expression::Expression(Parameter p1, Parameter p2, string oprtr){
  parameter1 = p1;
  parameter2 = p2;
  oper = oprtr;
}
Expression::~Expression(){}

string Expression::toString(){
  string output = "";
  output += "(";
  output += parameter1.toString();
  output += oper;
  output += parameter2.toString();
  output += ")";
  return output;
}
