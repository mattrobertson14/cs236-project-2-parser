#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "DatalogProgram.h"

using namespace std;

/*********** Constructor/Destructor ***********/

DatalogProgram::DatalogProgram(vector<Token> t){
  tokens = t;
}
DatalogProgram::~DatalogProgram(){}


/*********** Grammar Functions ***********/

bool DatalogProgram::parse(){
  bool schemesCheck = match(SCHEMES) && match(COLON) && scheme() && schemeList();
  bool factsCheck = match(FACTS) && match(COLON) && factList();
  bool rulesCheck = match(RULES) && match(COLON) && ruleList();
  bool queriesCheck = match(QUERIES) && match(COLON) && query() && queryList();
  return schemesCheck && factsCheck && rulesCheck && queriesCheck;
}

bool DatalogProgram::scheme(){
  return match(ID) && match(LEFT_PAREN) && match(ID) && idList() && match(RIGHT_PAREN);
}

bool DatalogProgram::schemeList(){
  return ( tokens[next].getType() == FACTS ) || ( scheme() && schemeList() );
}

bool DatalogProgram::idList(){
  return ( tokens[next].getType() == RIGHT_PAREN ) || ( (match(COMMA) && match(ID) && idList()) );
}

bool DatalogProgram::fact(){
  return match(ID) && match(LEFT_PAREN) && match(STRING) && stringList() && match(RIGHT_PAREN) && match(PERIOD);
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

  return match(STRING) || match(ID) || expression();
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
  return ( tokens[next].getType() == RIGHT_PAREN ) || ( match(COMMA) && match(STRING) && stringList() );
}



/*********** Helper Functions ***********/

bool DatalogProgram::match(int type){
  if (tokens[next].getType() == type){
    //cout<<tokens[next].output()<<endl;
    next++;
    return true;
  } else {
    throw(tokens[next]);
    return false;
  }
}
