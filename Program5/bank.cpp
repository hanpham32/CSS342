#include <iostream>
#include <fstream>
#include "fund.h"
// #include "bstree.h"
#include "transaction.h"
#include "transaction_queue.h"
#include <vector>
#include <string>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    std::fstream file("example.txt");
    std::string line;
    TransactionQueue<Transaction> queue;

    while (getline(file, line))
    {
        Transaction t(line);
        queue.Push(t);
    }

    std::cout << "Size of queue: " << queue.Size() << std::endl;

    // BSTree tree;

    std::vector<Fund> funds(8);
    for (int i = 0; i <= 7; i++)
    {
        funds[i] = Fund();
    }
}