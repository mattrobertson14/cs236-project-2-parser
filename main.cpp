#include "Scanner.h"
#include "Token.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Scanner scanner;
  scanner.scan(argv[1]);
  cout<<scanner.outputAllTokens()<<endl;



  //TESTS
  string test1 = "(PERIOD,\".\",1)\n(COMMA,\",\",2)\n(STRING,\"\'a string\'\",3)\n(COMMENT,\"#A comment\",4)\n(SCHEMES,\"Schemes\",5)\n(ID,\"FactsRules\",6)\n(COLON,\":\",7)\n(COLON_DASH,\":-\",7)\n(EOF,\"\",8)\nTotal Tokens = 9";
  //bool test1Res = (test1 == scanner.outputAllTokens());
  //cout<<endl<<endl<<endl<<"TEST 1 PASSED (1-YES 0-NO): "<<test1Res<<endl;
  return 0;
}
