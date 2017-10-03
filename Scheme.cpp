#include <string>
#include <vector>
#include "Scheme.h"

using namespace std;



Scheme::Scheme(string str){
  id = str;
}
Scheme::~Scheme(){}

void Scheme::addIDToList(string str){
  id_list.push_back(str);
}

string Scheme::toString(){
  string output = "";
  output += id+"("+id_list[0];
  for (int i = 1; i < id_list.size(); i++){
    output += ","+id_list[i];
  }
  output += ")";

  return output;
}
