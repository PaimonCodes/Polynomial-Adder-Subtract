#include <sstream>
#include "polynomial.h"

void process(const std::string& input, polynomial* expression) 
{
    std::istringstream extract(input);
    std::string coefficient;
    while(std::getline(extract, coefficient, ',')) 
    {
        expression->prepend(stoi(coefficient));
    }
}

polynomial* operate(const std::string& operation, const polynomial& a, const polynomial& b) 
{
    if (operation == "a" || operation == "add") 
    {
        return a + b;
    } 
    else if (operation == "s" || operation == "subtract") 
    {
        return a - b;
    } 
    else 
    {
        return nullptr;
    }
}

int main() 
{
    polynomial a;
    std::string inputA;
    std::cout << "Please enter the first polynomial [e.g., 4,5,10,2]: ";
    std::cin >> inputA;
    process(inputA, &a);

    polynomial b;
    std::string inputB;
    std::cout << "Please enter the second polynomial [e.g., 7,9,6]: ";
    std::cin >> inputB;
    process(inputB, &b);

    std::string operation;
    std::cout << "Please enter operation [a]dd/[s]ubtract: ";
    std::cin >> operation;

    polynomial* result = operate(operation, a, b);
    if (result == nullptr) 
    {
        std::cout << "Invalid operation." << std::endl;
    } 
    else 
    {
        result->dump();
    }
} 