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
    Transaction(std::string line);

    friend std::ostream &operator<<(std::ostream &os, const Transaction &transaction);

    char c() const;
    std::string first_name() const;
    std::string last_name() const;
    int id() const;
    int fund() const;
    int amount() const;
    int to_id() const;
    int to_fund() const;

    std::string TransactionToString() const;

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