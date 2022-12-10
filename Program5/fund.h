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
    Fund() : balance_(0){};

    void Deposit(int amount)
    {
        balance_ += amount;
    }
    void Withdraw(int amount)
    {
        balance_ -= amount;
    }
    void Transfer(Fund &to, int amount)
    {
        balance_ -= amount;
        to.balance_ += amount;
    }
    friend std::ostream &operator<<(std::ostream &os, Fund &fund);

    int balance() const
    {
        return balance_;
    }

    void AddHistory(std::string line)
    {
        history_.push_back(line);
    }

    void PrintAllHistory() const
    {
        for (int i = 0; i < history_.size(); i++)
        {
            std::cout << history_[i] << std::endl;
        }
    }

private:
    int balance_;
    std::vector<std::string> history_;
};

#endif
