#include <iostream>
#include "int_stack.h"
using namespace std;

int main()
{
    IntStack stack;
    stack.Push(7);
    stack.Push(3);

    int value = 0;
    if (stack.Pop(value))
    {
        cout << "Top value: " << value << endl;
    }
}