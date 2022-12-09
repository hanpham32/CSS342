#include <iostream>
#include <queue>
#include "transaction.h"

#ifndef TRANSACTION_QUEUE_H_
#define TRANSACTION_QUEUE_H_

class Node
{
public:
    Node(Transaction data) : data_(data), next_(nullptr) {}
    Transaction data_;
    Node *next_;
};

class TransactionQueue
{
private:
    Node *front_;
    Node *back_;
    int count_ = 0;

public:
    TransactionQueue() : front_(nullptr), back_(nullptr) {}
    ~TransactionQueue()
    {
        Node *curr = front_;
        while (curr)
        {
            Node *next = curr->next_;
            delete curr;
            curr = next;
        }
    }

    void Push(Transaction data)
    {
        Node *ins_node = new Node(data);

        if (!front_)
        {
            front_ = back_ = ins_node;
        }
        else
        {
            back_->next_ = ins_node;
            back_ = ins_node;
        }
    }

    void Pop() throw(exception)
    {
        if (!front_)
        {
            throw exception("Queue is empty");
        }
    }

    bool isEmpty() const
    {
        return (count_ == 0 ? true : false);
    }

    bool Size() const
    {
        return count_;
    }
};

#endif