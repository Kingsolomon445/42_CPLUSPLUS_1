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

class RPN
{
    private:
        RPN();
        RPN(const RPN & other);
        ~RPN();

        RPN & operator=(const RPN & other);

    public:
        static void sortOps(std::list<int> &operands, std::string opArg);
};

#endif