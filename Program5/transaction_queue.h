#include <iostream>
#include <queue>
#include "transaction.h"

#ifndef TRANSACTION_QUEUE_H_
#define TRANSACTION_QUEUE_H_

// class Node
// {
// public:
//     Node(Transaction data) : data_(data), next_(nullptr) {}
//     Transaction data_;
//     Node *next_;
// };

class TransactionQueue
{
private:
    // Node *front_;
    // Node *back_;
    int count_ = 0;

public:
    void Push(Transaction data)
    {
    }

    // CANNOT THROW EXCEPTION?
    void Pop()
    {
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