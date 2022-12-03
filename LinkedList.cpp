#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedListNode::LinkedListNode() : coefficient(0), exponent(0), next(nullptr) {}

LinkedListNode::LinkedListNode(const int& a) : coefficient(a), exponent(0), next(nullptr) {}

LinkedListNode::LinkedListNode(const int& a, const int& b) : coefficient(a), exponent(b), next(nullptr) {}

void LinkedList::Append(const int& data) {
    if (head == nullptr) {
        head = new LinkedListNode(data);
        tail = head;
    } else {
        LinkedListNode* newNode = new LinkedListNode(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::Prepend(const int& data) {
    if (head == nullptr) {
        head = new LinkedListNode(data);
        tail = head;
    } else {
        LinkedListNode* newNode = new LinkedListNode(data);
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::Prepend(LinkedListNode* node) {
    if (head == nullptr) {
        head = node;
        tail = head;
    } else {
        node->next = head;
        head = node;
    }
}


LinkedList* LinkedList::operator+(const LinkedList& rhs) const {
    LinkedList* result = new LinkedList;
    LinkedListNode* currentNodeA = head;
    LinkedListNode* currentNodeB = rhs.head;

    int exponent = 0;
    while (currentNodeA != nullptr && currentNodeB != nullptr) {
        LinkedListNode* sumNode = new LinkedListNode(currentNodeA->coefficient + currentNodeB->coefficient, exponent);
        result->Prepend(sumNode);
        currentNodeA = currentNodeA->next;
        currentNodeB = currentNodeB->next;
        exponent++;
    }

    if (currentNodeA == nullptr && currentNodeB == nullptr) {
        return result;
    } else if (currentNodeA == nullptr) {   // currentNodeB != nullptr
        while (currentNodeB != nullptr) {
            LinkedListNode* sumNode = new LinkedListNode(currentNodeB->coefficient, exponent);
            result->Prepend(sumNode);
            currentNodeB = currentNodeB->next;
            exponent++;
        }
        return result;
    } else {    // currentNodeA != nullptr
        while (currentNodeA != nullptr) {
            LinkedListNode* sumNode = new LinkedListNode(currentNodeA->coefficient, exponent);
            result->Prepend(sumNode);
            currentNodeA = currentNodeA->next;
            exponent++;
        }
        return result;
    }
}

LinkedList* LinkedList::operator-(const LinkedList& rhs) const {
    LinkedList* result = new LinkedList;
    LinkedListNode* currentNodeA = head;
    LinkedListNode* currentNodeB = rhs.head;

    int exponent = 0;
    while (currentNodeA != nullptr && currentNodeB != nullptr) {
        LinkedListNode* diffNode = new LinkedListNode(currentNodeA->coefficient - currentNodeB->coefficient, exponent);
        result->Prepend(diffNode);
        currentNodeA = currentNodeA->next;
        currentNodeB = currentNodeB->next;
        exponent++;
    }

    if (currentNodeA == nullptr && currentNodeB == nullptr) {
        return result;
    } else if (currentNodeA == nullptr) {   // currentNodeB != nullptr
        while (currentNodeB != nullptr) {
            LinkedListNode* diffNode = new LinkedListNode(-(currentNodeB->coefficient), exponent);
            result->Prepend(diffNode);
            currentNodeB = currentNodeB->next;
            exponent++;
        }
        return result;
    } else {    // currentNodeA != nullptr
        while (currentNodeA != nullptr) {
            LinkedListNode* diffNode = new LinkedListNode(currentNodeA->coefficient, exponent);
            result->Prepend(diffNode);
            currentNodeA = currentNodeA->next;
            exponent++;
        }
        return result;
    }
}


void LinkedList::dump() {
    LinkedListNode* currentNode = head;
    while (currentNode->next != nullptr) {
        std::cout << currentNode->coefficient << "y^" << currentNode->exponent << " + "; 
        currentNode = currentNode->next;
    }
    std::cout << currentNode->coefficient << std::endl;
}