// Copyright 2021 ccc

#include <iostream>
#include <cstdlib>
#include "postfix.h"


int main() {
std::string inf("(2 + 8.3) * (6 - 3.2)");
std::string postf = infix2postfix(inf);
std::cout << postf << std::endl;
return 0;
}
