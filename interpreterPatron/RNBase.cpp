#include <string.h>
#include "RNBase.hpp"

char  Thousand::one(){ return this->One; }
char* Thousand::four(){ return this->Four; }
char  Thousand::five(){ return this->Five; }
char* Thousand::nine(){ return this->Nine; }
int   Thousand::multiplier(){ return 1000; }

char  Hundred::one(){ return this->One; }
char* Hundred::four(){ return this->Four; }
char  Hundred::five(){ return this->Five; }
char* Hundred::nine(){ return this->Nine; }
int   Hundred::multiplier(){ return 100; }


char  Ten::one(){ return this->One; }
char* Ten::four(){ return this->Four; }
char  Ten::five(){ return this->Five; }
char* Ten::nine(){ return this->Nine; }
int   Ten::multiplier(){ return 10; }

char  One::one(){ return this->_One; }
char* One::four(){ return this->Four; }
char  One::five(){ return this->Five; }
char* One::nine(){ return this->Nine; }
int   One::multiplier(){ return 1; }
