#include <iostream>
#include "fund.h"
// #include "bstree.h"
#include "transaction.h"
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::cout << argv[1] << std::endl;
    char c = argv[1][0];

    switch (c)
    {
    case 'O':
        std::cout << "To Open..." << std::endl;
        // Transaction t(argv[2]);
        break;
    case 'D':
        std::cout << "To Display..." << std::endl;
        break;
    case 'W':
        std::cout << "To Withdraw..." << std::endl;
        break;
    case 'T':
        std::cout << "To Transfer..." << std::endl;
        break;
    case 'A':
        std::cout << "To Display All Funds..." << std::endl;
        break;
    case 'F':
        if (argc != 3)
        {
            std::cout << "Invalid amount of argument(s) passed in" << std::endl;
            break;
        }
        std::cout << "To Display A Fund..." << std::endl;
        break;
    }

    // BSTree tree;

    std::vector<Fund> funds(8);
    for (int i = 0; i <= 7; i++)
    {
        funds[i] = Fund();
    }
}