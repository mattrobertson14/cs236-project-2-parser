#pragma once
#include <string>
#include <vector>

using namespace std;

class Scheme {
public:
  Scheme(string str);
  ~Scheme();

  void addIDToList(string str);
  string toString();

private:
  string id;
  vector<string> id_list;
};
