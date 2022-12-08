/*
FileName: fund.h
Description: header and implementation of fund
Created On: Dec 7th, 2022
Author: Hannah Pham
Course: CSS 342 B Fall 22
Instructor: Robert Dimpsey
*/

#include <iostream>

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
    void Display() const;
    friend std::ostream &operator<<(std::ostream &os, Fund &fund);

private:
    int amount_;
};

#endif

Fund::Fund() : amount_(0)
{
}

void Fund::Display() const
{
    std::cout << "Current amount in fund: " << amount_ << std::endl;
}

void Fund::Deposit(int amount)
{
    amount_ += amount;
}

void Fund::Withdraw(int amount)
{
    amount_ -= amount;
}

void Fund::Transfer(Fund &rhs, int amount)
{
    amount_ -= amount;
    rhs.amount_ += amount;
}
