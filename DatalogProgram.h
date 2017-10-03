#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Token.h"
#include "Scanner.h"
#include "Scheme.h"
#include "Fact.h"

using namespace std;

class DatalogProgram {
public:
  DatalogProgram();
  ~DatalogProgram();

  // Enumerated values for the token types
  enum tokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES,	FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, EOTF};

  bool parse(vector<Token> t);
  bool matchScheme(int type, string part_of);
  bool matchFact(int type);
  bool matchRule(int type, string part_of);
  bool matchQuery(int type, string part_of);
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
  string toString();


private:
  vector<Token> tokens;
  vector<Scheme> schemes;
  vector<Fact> facts;
  int next = 0;

};
