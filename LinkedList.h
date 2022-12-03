#include <string>
#include <iostream>

class LinkedList;

class LinkedListNode {
 public:
   LinkedListNode();
   LinkedListNode(const int& a);
   LinkedListNode(const int& a, const int& b);
 private:
   int coefficient;
   int exponent;
   LinkedListNode* next;

   friend LinkedList;
};

class LinkedList {
 public:
   LinkedList();
   void Append(const int& data);
   void Prepend(const int& data);
   LinkedList* operator+(const LinkedList& rhs) const;
   LinkedList* operator-(const LinkedList& rhs) const;
   void dump();

 private:
   void Prepend(LinkedListNode* node);

   LinkedListNode* head;
   LinkedListNode* tail;
};