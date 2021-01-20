// Copyright 2021 ccc

#include <iostream>
#include <cstdlib>
#include "postfix.h"


std::string inf("(2 + 8.3) * (6 - 3.2)");
std::string postf = infix2postfix(inf);

int main() {
std::cout << postf << std::endl;
return 0;
}
