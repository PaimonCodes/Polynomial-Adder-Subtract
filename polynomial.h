#include <string>
#include <iostream>

class polynomial;

class polynomial_node 
{
 public:
   polynomial_node();
   polynomial_node(const int& a);
   polynomial_node(const int& a, const int& b);
 private:
   int coefficient;
   int exponent;
   polynomial_node* next;

   friend polynomial;
};

class polynomial 
{
 public:
   polynomial();
   ~polynomial();
   
   void prepend(const int& data);
   polynomial* operator+(const polynomial& rhs) const;
   polynomial* operator-(const polynomial& rhs) const;
   void dump();

 private:
   void prepend(polynomial_node* node);
   void bring_down(polynomial_node*& a, polynomial* result, int* exponent) const;
   void subtract_trailing_subtrahend(polynomial_node*& b, polynomial* result, int* exponent) const;

   void perform_addition(polynomial_node*& a, polynomial_node*& b,
                        polynomial* result, int* exponent) const;
   void perform_subtraction(polynomial_node*& a, polynomial_node*& b,
                        polynomial* result, int* exponent) const;                  

   polynomial_node* head;
   polynomial_node* tail;
};