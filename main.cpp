#include "Scanner.h"
#include "Token.h"
#include "DatalogProgram.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  Scanner scanner;
  vector<Token> scannedTokens = scanner.scan(argv[1]);
  DatalogProgram datalogProgram = DatalogProgram(scannedTokens);

  try {
    datalogProgram.parse();
    cout<<"Success!"<<endl;
  } catch( Token token ){
    cout<<"Failure!"<<endl;
    cout<<"  "<<token.output()<<endl;
  }

}
