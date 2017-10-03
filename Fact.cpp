#include <string>
#include <vector>
#include "Fact.h"

using namespace std;



Fact::Fact(string str){
  id = str;
}
Fact::~Fact(){}

void Fact::addStringToList(string str){
  string_list.push_back(str);
}

string Fact::toString(){
  string output = "";
  output += id+"("+string_list[0];
  for (int i = 1; i < string_list.size(); i++){
    output += ","+string_list[i];
  }
  output += ").";

  return output;
}
