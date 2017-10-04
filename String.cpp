#include <string>
#include <vector>
#include "String.h"

using namespace std;

String::String(string str){
  value = str;
}
String::~String(){}

string String::getValue(){
  return value;
}

string String::toString(){
  string output = "";
  output += value;
  return output;
}
