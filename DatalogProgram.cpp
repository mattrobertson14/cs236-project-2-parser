#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "DatalogProgram.h"

using namespace std;

/*********** Constructor/Destructor ***********/

DatalogProgram::DatalogProgram(){}
DatalogProgram::~DatalogProgram(){
  next = 0;
  tokens.clear();
}


/*********** Grammar Functions Start ***********/

bool DatalogProgram::parse(vector<Token> t){
  tokens = t;
  bool schemesCheck = match(SCHEMES) && match(COLON) && scheme() && schemeList();
  bool factsCheck = match(FACTS) && match(COLON) && factList();
  bool rulesCheck = match(RULES) && match(COLON) && ruleList();
  bool queriesCheck = match(QUERIES) && match(COLON) && query() && queryList();
  return schemesCheck && factsCheck && rulesCheck && queriesCheck;
}

bool DatalogProgram::scheme(){
  return matchScheme(ID, "head_id") && match(LEFT_PAREN) && matchScheme(ID, "id_list") && idList() && match(RIGHT_PAREN);
}

bool DatalogProgram::schemeList(){
  return ( tokens[next].getType() == FACTS ) || ( scheme() && schemeList() );
}

bool DatalogProgram::idList(){
  return ( tokens[next].getType() == RIGHT_PAREN ) || ( (match(COMMA) && matchScheme(ID, "id_list") && idList()) );
}

bool DatalogProgram::fact(){
  return matchFact(ID) && match(LEFT_PAREN) && matchFact(STRING) && stringList() && match(RIGHT_PAREN) && match(PERIOD);
}

bool DatalogProgram::factList(){
  return ( tokens[next].getType() == RULES ) || ( fact() && factList() );
}

bool DatalogProgram::rule(){
  return headPredicate() && match(COLON_DASH) && predicate() && predicateList() && match(PERIOD);
}

bool DatalogProgram::ruleList(){
  return ( tokens[next].getType() == QUERIES ) || ( rule() && ruleList() );
}

bool DatalogProgram::headPredicate(){
  return match(ID) && match(LEFT_PAREN) && match(ID) && idList() && match(RIGHT_PAREN);
}

bool DatalogProgram::predicate(){
  return match(ID) && match(LEFT_PAREN) && parameter() && parameterList() && match(RIGHT_PAREN);
}

bool DatalogProgram::predicateList(){
  return ( tokens[next].getType() == PERIOD ) || ( match(COMMA) && predicate() && predicateList() );
}

bool DatalogProgram::parameter(){
  if (tokens[next].getType() == STRING){
    return match(STRING);
  } else if (tokens[next].getType() == ID){
    return match(ID);
  } else {
    return expression();
  }
}

bool DatalogProgram::parameterList(){
  return ( tokens[next].getType() == RIGHT_PAREN) || ( match(COMMA) && parameter() && parameterList() );
}

bool DatalogProgram::expression(){
  return match(LEFT_PAREN) && parameter() && checkOperator() && parameter() && match(RIGHT_PAREN);
}

bool DatalogProgram::checkOperator(){
  if (tokens[next].getType() == ADD)
    return match(ADD);
  return match(MULTIPLY);
}

bool DatalogProgram::query(){
  return predicate() && match(Q_MARK);
}

bool DatalogProgram::queryList(){
  return ( tokens[next].getType() == EOTF ) || ( query() && queryList() );
}

bool DatalogProgram::stringList(){
  return ( tokens[next].getType() == RIGHT_PAREN ) || ( match(COMMA) && matchFact(STRING) && stringList() );
}

/***********************************************************
 ***********************************************************
 ********************** E   N   D **************************
 ***********************************************************
 ***********************************************************/

/*********** Helper Functions Start ***********/

bool DatalogProgram::matchScheme(int type, string part_of){
  string token_value = tokens[next].getValue();
  if (tokens[next].getType() == type){
    if (part_of == "head_id"){
      Scheme s = Scheme(token_value);
      schemes.push_back(s);
    }
    if (part_of == "id_list"){
      schemes[schemes.size()-1].addIDToList(token_value);
    }
    next++;
    return true;
  } else {
    throw(tokens[next]);
    return false;
  }
}

bool DatalogProgram::matchFact(int type){
  string token_value = tokens[next].getValue();
  if (tokens[next].getType() == type){
    if (type == ID){
      Fact f = Fact(token_value);
      facts.push_back(f);
    }
    if (type == STRING){
      facts[facts.size()-1].addStringToList(token_value);
    }
    next++;
    return true;
  } else {
    throw(tokens[next]);
    return false;
  }
}

bool DatalogProgram::matchRule(int type, string part_of){
  if (tokens[next].getType() == type){
    next++;
    return true;
  } else {
    throw(tokens[next]);
    return false;
  }
}

bool DatalogProgram::matchQuery(int type, string part_of){
  if (tokens[next].getType() == type){
    next++;
    return true;
  } else {
    throw(tokens[next]);
    return false;
  }
}

bool DatalogProgram::match(int type){
  if (tokens[next].getType() == type){
    next++;
    return true;
  } else {
    throw(tokens[next]);
    return false;
  }
}

/***********************************************************
 ***********************************************************
 ********************** E   N   D **************************
 ***********************************************************
 ***********************************************************/

/*********** Output Functions ***********/

string DatalogProgram::toString(){
  string output = "";
  output += "Schemes("+to_string(schemes.size())+"):\n";
  for (int i = 0; i < schemes.size(); i++){
    output += "  "+schemes[i].toString()+"\n";
  }
  output += "Facts("+to_string(facts.size())+"):\n";
  for (int i = 0; i < facts.size(); i++){
    output += "  "+facts[i].toString()+"\n";
  }
  return output;
}
