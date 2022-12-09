/*
FileName: transaction.h
Description: header and implementation of transaction
Created On: November 7th, 2022
Author: Hannah Pham
Course: CSS 342 B Fall 22
Instructor: Robert Dimpsey
*/
#include <string>
#include <iostream>
#include <sstream>

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

class Transaction
{
public:
    Transaction(std::string line) : id_(0)
    {
        std::string next;
        std::istringstream iss(line);

        // Extract transaction type and account's id
        iss >> next;
        c_ = next[0];
        iss >> next;
        id_ = stoi(next);

        switch (c_)
        {
        case 'O':
        {
            iss >> next;
            first_name_ = next;
            iss >> next;
            last_name_ = next;
            std::cout << "Opened a new account: " << last_name_ << ", " << first_name_ << " id: " << id_ << std::endl;
            break;
        }
        case 'D':
        {
            iss >> next;
            fund_ = stoi(next);
            iss >> next;
            amount_ = stoi(next);
            std::cout << "Deposited " << amount_ << " to fund " << fund_ << std::endl;
            break;
        }
        case 'W':
        {
            iss >> next;
            fund_ = stoi(next);
            iss >> next;
            amount_ = stoi(next);
            break;
        }
        case 'T':
        {
            iss >> next;
            fund_ = stoi(next);
            iss >> next;
            to_id_ = stoi(next);
            iss >> next;
            to_fund_ = stoi(next);
            iss >> next;
            amount_ = stoi(next);
            break;
        }
        case 'A':
        {
            break;
        }
        case 'F':
        {
            iss >> next;
            fund_ = stoi(next);
            break;
        }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &transaction)
    {
        os << transaction.c_ << " " << transaction.id_ << std::endl;
        return os;
    }

private:
    char c_;
    int id_;
    int to_id_;
    std::string first_name_;
    std::string last_name_;
    int fund_;
    int to_fund_;
    int amount_;
};
#endif