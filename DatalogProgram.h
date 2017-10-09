#pragma once
#include <string>
#include <vector>
#include <set>
#include "scanner_files/Token.h"
#include "subclasses/Schemes.h"
#include "subclasses/Facts.h"
#include "subclasses/Rules.h"
#include "subclasses/Queries.h"

using namespace std;

class DatalogProgram {
public:
  DatalogProgram(vector<Token> tokens){
    schemes = new Schemes(tokens);
    index = schemes->getIndex();
    facts = new Facts(tokens, index);
    index = facts->getIndex();
    rules = new Rules(tokens, index);
    index = rules->getIndex();
    queries = new Queries(tokens, index);
  }
  ~DatalogProgram(){}

  // Enumerated values for the token types
  enum tokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES,	FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, EOTF};

  string toString(){
    string output = "";
    output += schemes->toString();
    output += facts->toString();
    output += rules->toString();
    output += queries->toString();
    output += facts->outputDomain();
  	return output;
  }

private:
  Schemes *schemes;
  Facts *facts;
  Rules *rules;
  Queries *queries;
  int index = 0;

};
