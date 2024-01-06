#include "RPN.hpp"

std::list<int> operands;
std::list<std::string> operators;

int multiply(int operand1, int operand2)
{
    return operand1 * operand2;
}
int add(int operand1, int operand2)
{
    return operand1 + operand2;
}
int subtract(int operand1, int operand2)
{
    return operand1 - operand2;
}
int divide(int operand1, int operand2)
{
    return operand1 / operand2;
}

int searchOp(std::string op)
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

void runOps()
{
    int (*operations[4])(int, int) = {&multiply, &add, &subtract, &divide};

    while(!operators.empty())
    {
        int valueA = operands.front();
        operands.pop_front();
        int valueB = operands.front();
        operands.pop_front();
        operands.push_front(operations[searchOp(operators.front())](valueA, valueB));
        operators.pop_front();
    }
    std::cout << "Result is: " << operands.front() << std::endl;
}


int checkOpArg(std::string op)
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

void sortOps(std::string opArg)
{
    std::stringstream ss(opArg);
    std::string tok;
    int pos = 0;

    while (std::getline(ss, tok, ' '))
    {
        std::stringstream ssOperand;
        int operand;
        tok.erase(std::remove_if(tok.begin(), tok.end(), isspace), tok.end());
        if (pos < 2 || (pos % 2))
        {
            if (checkOpArg(tok) == OPERATOR)
                throw std::runtime_error("Operand-Operator Mismatch");
            ssOperand << tok;
            ssOperand >> operand;
            operands.push_back(operand);
        }
        else
        {
            if (checkOpArg(tok) == OPERAND)
                throw std::runtime_error("Operator-Operand Mismatch");
            operators.push_back(tok);
        }
        pos++;
    }
    if (operands.size() < 2 || (operands.size() - 1 != operators.size()))
        throw std::runtime_error("Error");
    runOps();
}