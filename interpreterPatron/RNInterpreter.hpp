#include "RNBase.hpp"

class RNInterpreter
{
  public:
    RNInterpreter(); // ctor for client

    // ctor for subclasses, avoids infinite loop
    int interpret(char*); // interpret() for client
  private:
    RNBase *thousands;
    RNBase *hundreds;
    RNBase *tens;
    RNBase *ones;
};
