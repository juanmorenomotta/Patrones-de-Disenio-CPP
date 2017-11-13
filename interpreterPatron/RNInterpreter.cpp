#include <string.h>
#include "RNInterpreter.hpp"

RNInterpreter::RNInterpreter()
{
  // use 1-arg ctor to avoid infinite loop
  thousands = new Thousand();
  hundreds = new Hundred();
  tens = new Ten();
  ones = new One();
}

int RNInterpreter::interpret(char *input)
{
  int total;
  total = 0;
  thousands->interpret(input, total);
  hundreds->interpret(input, total);
  tens->interpret(input, total);
  ones->interpret(input, total);
  if (strcmp(input, ""))
  // si input es invalido, retorna 0
    return 0;
  return total;
}
