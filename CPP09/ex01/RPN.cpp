#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & other)
{
    *this = other;
}

RPN & RPN::operator=(const RPN & other)
{
    if (this != &other) {}

    return *this;
}

static int multiply(int operand1, int operand2)
{
    return operand1 * operand2;
}
static int add(int operand1, int operand2)
{
    return operand1 + operand2;
}
static int subtract(int operand1, int operand2)
{
    return operand1 - operand2;
}
static int divide(int operand1, int operand2)
{
    if (operand2 == 0)
        throw std::runtime_error("Divison by Zero!");
    return operand1 / operand2;
}

static int searchOp(std::string op)
{
    std::string opStr[4] = {"*", "+", "-", "/"};
    int idx;

    for (int i = 0; i < 4; i++)
    {
        if (opStr[i] == op)
            idx = i;
    }
    return idx;
}

static int checkOpArg(std::string op)
{
    if (op == "+" || op == "-" || op == "/" || op == "*")
        return 2;
    for (int i = 0; i < (int)op.size(); i++)
    {
        if (op[i] < 48 || op[i] > 57)
            throw std::runtime_error("Error");
    }
    return 1;
}

void RPN::sortOps(std::list<int> & operands, std::string opArg)
{
    int (*operations[4])(int, int) = {&multiply, &add, &subtract, &divide};
    std::stringstream ss(opArg);
    std::string tok;

    while (ss >> tok)
    {
        tok.erase(std::remove_if(tok.begin(), tok.end(), isspace), tok.end());
        if (checkOpArg(tok) == OPERATOR)
        {
            if (operands.size() < 2)
                throw std::runtime_error("Error");
            int valueB = operands.front();
            operands.pop_front();
            int valueA = operands.front();
            operands.pop_front();
            operands.push_front(operations[searchOp(tok)](valueA, valueB));
        }
        else if (checkOpArg(tok) == OPERAND)
        {
            std::stringstream ssOperand;
            int operand;
            ssOperand << tok;
            ssOperand >> operand;
            if (operand >= 10)
                throw std::runtime_error("Error");
            operands.push_front(operand);
        }
    }
    if (operands.size() > 1)
        throw std::runtime_error("Error");
    std::cout << "Result is: " << operands.front() << std::endl;
}