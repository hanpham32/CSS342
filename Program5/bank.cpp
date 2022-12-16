/*
FileName: bank.cpp
Description: main bank driver
Created On: November 7th, 2022
Author: Hannah Pham
Course: CSS 342 B Fall 22
Instructor: Robert Dimpsey
*/
#include <iostream>
#include <fstream>
#include "fund.h"
#include "bstree.h"
#include "transaction.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>

int main(int argc, char *argv[])
{
    std::fstream file(argv[1]);
    std::string line;

    std::queue<Transaction> q;

    BSTree tree;

    // PHASE 1 : Read file
    while (getline(file, line))
    {
        Transaction t(line);
        q.push(t);
    }
    std::cout << "Total size of transaction queue read: " << q.size() << std::endl;

    // PHASE 2: Execute each transaction based on FIFO queue order
    while (!q.empty())
    {
        Transaction t = q.front();
        if (t.c() == 'O')
        {
            Account *acct = new Account(t.id(), t.last_name(), t.first_name());
            tree.Insert(acct);
        }
        else if (t.c() == 'D')
        {
            Account *temp_acct;
            if (tree.Retrieve(t.id(), temp_acct))
            {
                temp_acct->Deposit(t.fund(), t.amount());
                std::string line = t.TransactionToString();
                temp_acct->AddHistory(t.fund(), line);
            }
        }
        else if (t.c() == 'W')
        {
            Account *temp_acct;
            if (tree.Retrieve(t.id(), temp_acct))
            {
                temp_acct->Withdraw(t.fund(), t.amount());
                std::string line = t.TransactionToString();
                temp_acct->AddHistory(t.fund(), line);
            }
        }
        else if (t.c() == 'T')
        {
            Account *temp_acct;
            if (tree.Retrieve(t.id(), temp_acct))
            {
                if (t.id() == t.to_id())
                {
                    temp_acct->Deposit(t.to_fund(), t.amount());
                    temp_acct->Withdraw(t.fund(), t.amount());
                }
                else
                {
                    Account *temp_acct2;
                    if (tree.Retrieve(t.to_id(), temp_acct2))
                    {
                        temp_acct2->Deposit(t.to_fund(), t.amount());
                        temp_acct->Withdraw(t.fund(), t.amount());
                    }
                }
            }
        }
        else if (t.c() == 'A')
        {
            Account *temp_acct;
            if (tree.Retrieve(t.id(), temp_acct))
            {
                temp_acct->PrintFundsHistory();
            }
        }
        else if (t.c() == 'F')
        {
            Account *temp_acct;
            if (tree.Retrieve(t.id(), temp_acct))
            {
                temp_acct->PrintFund(t.fund());
            }
        }
        else
        {
            std::cout << "Invalid transaction argument" << std::endl;
        }
        q.pop();
    }

    // Phase 3: Output
    std::cout << "FINAL BALANCES:" << std::endl;
}