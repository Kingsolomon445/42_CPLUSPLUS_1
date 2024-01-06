#ifndef RPN_H
#define RPN_H

#define OPERAND 1
#define OPERATOR 2

#include <list>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <string>

void sortOps(std::string opArg);
int searchOp(std::string op);
void runOps();

#endif