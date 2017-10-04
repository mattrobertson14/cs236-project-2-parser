#include <string>
#include <vector>
#include "Predicate.h"

using namespace std;

Predicate::Predicate(){}
Predicate::Predicate(string str){
  id = str;
}
Predicate::~Predicate(){}

void Predicate::addParameterToList(Parameter par){
  parameter_list.push_back(par);
}

string Predicate::toString(){
  string output = "";

  return output;
}
