// Copyright 2021 ccc

#include <iostream>
#include <cstdlib>
#include "postfix.h"


int main() {
std::string inf = "(2 + 8.3) * (6 - 3.2)";
std::string postf = infix2postfix(inf);
std::cout << postf << std::endl;
inf = "2 + 6 * 3 / (4 - 2)";
std::cout << infix2postfix(inf) << std::endl;
inf = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
std::cout << infix2postfix(inf) << std::endl;
return 0;
}
