#pragma once
#include <string>
#include <vector>

using namespace std;
// info on a Token to test
class Token {
public:
  Token(string t, string v, int lN);
  ~Token();

  string getType();
  string getValue();
  int getLineNumber();
  string output();

private:
  string type;
  string value;
  int lineNumber;
};
