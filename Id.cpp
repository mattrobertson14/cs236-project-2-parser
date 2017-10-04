#include <string>
#include <vector>
#include "Id.h"

using namespace std;

Id::Id(string str){
  value = str;
}
Id::~Id(){}

string Id::getValue(){
  return value;
}

string Id::toString(){
  string output = "";
  output += value;
  return output;
}
