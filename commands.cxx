#include <sstream>
#include "LinkedList.h"

void process(const std::string& input, LinkedList* expression) {
    std::istringstream extract(input);
    std::string coefficient;
    while(std::getline(extract, coefficient, ',')) {
        expression->Prepend(stoi(coefficient));
    }
}

LinkedList* operate(const std::string& operation, const LinkedList& a, const LinkedList& b) {
    if (operation == "a" || operation == "add") {
        return a + b;
    } else if (operation == "s" || operation == "subtract") {
        return a - b;
    } else {
        return nullptr;
    }
}

int main() {
    LinkedList a;
    std::string inputA;
    std::cout << "Please enter the first polynomial [e.g., 4,5,10,2]: ";
    std::cin >> inputA;
    process(inputA, &a);

    LinkedList b;
    std::string inputB;
    std::cout << "Please enter the second polynomial [e.g., 7,9,6]: ";
    std::cin >> inputB;
    process(inputB, &b);

    std::string operation;
    std::cout << "Please enter operation [a]dd/[s]ubtract: ";
    std::cin >> operation;

    LinkedList* result = operate(operation, a, b);
    if (result == nullptr) {
        std::cout << "Invalid operation." << std::endl;
    } else {
        result->dump();
    }
} 