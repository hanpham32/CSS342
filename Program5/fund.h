/*
FileName: fund.h
Description: header and implementation of fund
Created On: Dec 7th, 2022
Author: Hannah Pham
Course: CSS 342 B Fall 22
Instructor: Robert Dimpsey
*/

#include <iostream>
#include <vector>
#include <string>

#ifndef FUND_H_
#define FUND_H_

class Fund
{
public:
    // Constructor
    Fund();

    void Deposit(int amount);
    void Withdraw(int amount);
    void Transfer(Fund &to, int amount);

    int balance() const;
    void clear();

    void AddHistory(std::string line);
    void PrintAllHistory() const;

private:
    int balance_;
    std::vector<std::string> history_;
};

#endif
