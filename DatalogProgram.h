#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Token.h"
#include "Scanner.h"

using namespace std;

class DatalogProgram {
public:
  DatalogProgram(vector<Token> t);
  ~DatalogProgram();

  // Enumerated values for the token types
  enum tokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES,	FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, EOTF};

  bool parse();
  bool match(int type);
  bool scheme();
  bool schemeList();
  bool idList();
  bool fact();
  bool factList();
  bool rule();
  bool ruleList();
  bool headPredicate();
  bool predicate();
  bool predicateList();
  bool parameter();
  bool parameterList();
  bool expression();
  bool checkOperator();
  bool query();
  bool queryList();
  bool stringList();


private:
  vector<Token> tokens;
  int next = 0;

};
