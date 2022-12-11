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
            break;
        }
        case 'D':
        {
            iss >> next;
            fund_ = stoi(next);
            iss >> next;
            amount_ = stoi(next);
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

    char c() const
    {
        return c_;
    }
    std::string first_name() const
    {
        return first_name_;
    }
    std::string last_name() const
    {
        return last_name_;
    }
    int id() const
    {
        return id_;
    }
    int fund() const
    {
        return fund_;
    }
    int amount() const
    {
        return amount_;
    }
    int to_id() const
    {
        return to_id_;
    }
    int to_fund() const
    {
        return to_fund_;
    }

    std::string TransactionToString() const
    {
        char c = c_;
        std::string str;
        str.push_back(c_);
        switch (c)
        {
        case 'D':
        {
            str = std::to_string(id()) + " " + std::to_string(fund()) + " " + std::to_string(amount());
            return str;
        }
        case 'W':
        {
            str = std::to_string(id()) + " " + std::to_string(fund()) + " " + std::to_string(amount());
            return str;
        }
        case 'T':
        {
            std::string id_str = std::to_string(id());
            std::string fund_str = std::to_string(fund());
            std::string to_id_str = std::to_string(to_id());
            std::string to_fund_str = std::to_string(to_fund());
            str = id_str + fund_str + to_id_str + to_fund_str + std::to_string(amount());
        }
        }
        return str;
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