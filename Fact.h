#pragma once
#include <string>
#include <vector>

using namespace std;

class Fact {
public:
  Fact(string str);
  ~Fact();

  void addStringToList(string str);
  string toString();

private:
  string id;
  vector<string> string_list;
};
