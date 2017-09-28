#include <string>
#include "Token.h"

using namespace std;

Token::Token(string t, string v, int lN){
  type = t;
  value = v;
  lineNumber = lN;
}
Token::~Token(){}

string getType(){
  return type;
}

string getValue(){
  return value;
}

int getLineNumber(){
  return lineNumber;
}

string Token::output(){
  return "("+type+","+"\""+value+"\""+","+to_string(lineNumber)+")";
}
