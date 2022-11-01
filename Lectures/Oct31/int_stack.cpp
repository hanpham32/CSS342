#include "int_stack.h"

IntStack::IntStack() : head_(nullptr)
{
}

IntStack::IntStack(const IntStack &source)
{
    *this = source;
}

IntStack::~IntStack()
{
    int val;
    while (Pop(val))
        ;
}

bool IntStack::Push(int value)
{
    // Create a node
    Node *insert_node = new Node();
    insert_node->value = value;

    // Point to the beginning of the list
    insert_node->next = head_;

    // Point head_ to pointer insert_node
    head_ = insert_node;
    return true;
}

bool IntStack::Pop(int &value)
{
    if (head_ == nullptr)
    {
        return false;
    }
    else
    {
        Node *temp = head_;
        head_ = temp->next;
        int value = temp->value;
        delete temp;
        return true;
    }
}

std::ostream &operator<<(std::ostream stream, const IntStack &st)
{
    Node *p_node = st.head_;
    while (p_node != nullptr)
    {
        stream << p_node->value << " ";
        p_node = p_node->next;
    }
    return stream;
}
