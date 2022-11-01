#ifndef INT_STACK_H_
#define INT_STACK_H_
#include <iostream>
using namespace std;

struct Node
{
    int value = 0;
    Node *next = nullptr;
};

class IntStack
{
public:
    IntStack();
    IntStack(const IntStack &source);
    ~IntStack(); // Destructor
    bool Push(int value);
    bool Pop(int &value);

    // IntStack &operator=(const IntStack &stack);
    friend ostream &operator<<(ostream &stream, const IntStack &stack);

private:
    Node *head_;
};
#endif