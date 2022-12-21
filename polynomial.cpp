#include "polynomial.h"

polynomial::polynomial() : head(nullptr), tail(nullptr) {}

polynomial_node::polynomial_node() : coefficient(0), exponent(0), next(nullptr) {}

polynomial_node::polynomial_node(const int& a) : coefficient(a), exponent(0), next(nullptr) {}

polynomial_node::polynomial_node(const int& a, const int& b) : coefficient(a), exponent(b), next(nullptr) {}

void polynomial::prepend(const int& data) {
    if (head == nullptr) 
    {
        head = new polynomial_node(data);
        tail = head;
    } 
    else 
    {
        polynomial_node* newNode = new polynomial_node(data);
        newNode->next = head;
        head = newNode;
    }
}

void polynomial::prepend(polynomial_node* node) {
    if (head == nullptr) 
    {
        head = node;
        tail = head;
    } 
    else 
    {
        node->next = head;
        head = node;
    }
}

void polynomial::bring_down(polynomial_node*& a, polynomial* result, int* exponent) const {
    while (a != nullptr) 
    {
        polynomial_node* sum_node = new polynomial_node(a->coefficient, *exponent);
        result->prepend(sum_node);
        a = a->next;
        (*exponent)++;
    }    
}

void polynomial::perform_addition(polynomial_node*& a, polynomial_node*& b, polynomial* result, int* exponent) const {
    while (a != nullptr && b != nullptr) 
    {
        polynomial_node* sum_node = new polynomial_node(a->coefficient + b->coefficient, *exponent);
        result->prepend(sum_node);
        a = a->next;
        b = b->next;
        (*exponent)++;
    }
}

polynomial* polynomial::operator+(const polynomial& rhs) const {
    polynomial* result = new polynomial;
    polynomial_node* current_node_a = head;
    polynomial_node* current_node_b = rhs.head;
    
    int exponent = 0;
    perform_addition(current_node_a, current_node_b, result, &exponent);
    
    if (current_node_a == nullptr && current_node_b == nullptr) 
    {
        return result;
    } 
    else if (current_node_a == nullptr)
    {       
        // current_node_b != nullptr
        bring_down(current_node_b, result, &exponent);
        return result;
    } 
    else 
    {                 
        // current_node_a != nullptr
        bring_down(current_node_a, result, &exponent);
        return result;
    }
}

void polynomial::subtract_trailing_subtrahend(polynomial_node*& b, polynomial* result, int* exponent) const {
   while (b != nullptr) 
   {
        polynomial_node* diff_node = new polynomial_node(-(b->coefficient), *exponent);
        result->prepend(diff_node);
        b = b->next;
        (*exponent)++;
   }
}

void polynomial::perform_subtraction(polynomial_node*& a, polynomial_node*& b, polynomial* result, int* exponent) const {
    while (a != nullptr && b != nullptr) 
    {
        polynomial_node* diff_node = new polynomial_node(a->coefficient - b->coefficient, *exponent);
        result->prepend(diff_node);
        a = a->next;
        b = b->next;
        (*exponent)++;
    }
}

polynomial* polynomial::operator-(const polynomial& rhs) const {
    polynomial* result = new polynomial;
    polynomial_node* current_node_a = head;
    polynomial_node* current_node_b = rhs.head;

    int exponent = 0;
    perform_subtraction(current_node_a, current_node_b, result, &exponent);

    if (current_node_a == nullptr && current_node_b == nullptr) {
        return result;
    } 
    else if (current_node_a == nullptr) 
    {   
        // current_node_b != nullptr
        subtract_trailing_subtrahend(current_node_b, result, &exponent);
        return result;
    }
    else 
    {    
        // current_node_a != nullptr
        bring_down(current_node_a, result, &exponent);
        return result;
    }
}

void polynomial::dump() {
    polynomial_node* current_node = head;
    while (current_node->next != nullptr) {
        std::cout << current_node->coefficient << "y^" << current_node->exponent << " + "; 
        current_node = current_node->next;
    }
    std::cout << current_node->coefficient << std::endl;
}

polynomial::~polynomial() {
    polynomial_node* current_node = head;
    while (current_node != nullptr) 
    {
        current_node = current_node->next;
        delete head;
        head = current_node;
    }
}