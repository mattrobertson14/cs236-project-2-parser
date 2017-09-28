#include <string>
#include "Token.h"

using namespace std;

Token::Token(string t, string v, int lN){
  type = t;
  value = v;
  lineNumber = lN;
}
Token::~Token(){}

string Token::getType(){
  return type;
}

string Token::getValue(){
  return value;
}

int Token::getLineNumber(){
  return lineNumber;
}

string Token::output(){
  return "("+type+","+"\""+value+"\""+","+to_string(lineNumber)+")";
}
