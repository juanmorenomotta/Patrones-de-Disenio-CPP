#include <iostream>
#include "RNInterpreter.hpp"
using namespace std;

int main()
{
  RNInterpreter interpreter;
  char input[20];
  cout << "Ingrese Numero Romano: ";
  while (cin >> input)
  {
    cout << "   interpretacion es " << interpreter.interpret(input) << endl;
    cout << "Ingrese Numero Romano: ";
  }
}
