#include <string>
#include <vector>
#include "Rule.h"

using namespace std;


Rule::Rule(Predicate head){
  head_predicate = head;
}
Rule::~Rule(){}

void Rule::addPredicateToList(Predicate pred){
  predicate_list.push_back(pred);
}

void Rule::addParamToPred(Parameter par){
  predicate_list[predicate_list.size()-1].addParameterToList(par);
}

string Rule::toString(){
  string output = "";

  return output;
}
