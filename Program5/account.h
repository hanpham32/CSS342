/*
FileName: account.h
Description: header and implementation of account
Created On: November 27th, 2022
Author: Hannah Pham
Course: CSS 342 B Fall 22
Instructor: Robert Dimpsey
*/
#include <iostream>
#include <string>
#include <vector>
#include "fund.h"

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

const int kFunds = 8;
const char *kFundsName[kFunds] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond",
                                  "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund"};

class Account
{
public:
    Account() : id_(0), last_name_(""), first_name_("") {}

    Account(int id, std::string last_name, std::string first_name) : id_(id), last_name_(last_name), first_name_(first_name)
    {
        Fund f(0);
        for (int i = 0; i < kFunds; i++)
        {
            funds_.push_back(f);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Account &account)
    {
        os << account.first_name_ << account.last_name_ << "Account ID: " << account.id_ << std::endl;
        return os;
    }

    void print_account() const
    {
        std::cout << first_name() << " " << last_name() << " "
                  << "Account ID: " << id() << std::endl;
        for (int i = 0; i < kFunds; i++)
        {
            std::cout << "     " << kFundsName[i] << ": $" << funds_[i].balance() << std::endl;
        }
    }

    bool operator>(const Account &acct) const
    {
        if (id_ > acct.id_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(const Account &acct) const
    {
        if (id_ < acct.id_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const Account &acct) const
    {
        if (id_ == acct.id_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void operator=(const Account &rhs)
    {
        if (*this == rhs)
        {
            return;
        }
        id_ = rhs.id();
        first_name_ = rhs.first_name();
        last_name_ = rhs.last_name();
    }

    // Accessors
    std::string last_name() const
    {
        return last_name_;
    }
    std::string first_name() const
    {
        return first_name_;
    }
    int id() const
    {
        return id_;
    }

    // Add to fund
    void Deposit(int fund, int amount)
    {
        funds_[fund].Deposit(amount);
    }

    void Withdraw(int fund, int amount)
    {
        funds_[fund].Withdraw(amount);
    }
    void AddHistory(int fund, std::string line)
    {
        funds_[fund].AddHistory(line);
    }
    void PrintFundsHistory() const
    {
        std::cout << "Transaction History for " << first_name() << " " << last_name() << " by fund." << std::endl;
        for (int i = 0; i < kFunds; i++)
        {
            std::cout << kFundsName[i] << ": $" << funds_[i].balance() << std::endl;
            funds_[i].PrintAllHistory();
        }
    }

    void PrintFund(int fund)
    {
        std::cout << "Transaction History for " << first_name() << " " << last_name() << " " << kFundsName[fund] << ": $" << funds_[fund].balance() << std::endl;
        funds_[fund].PrintAllHistory();
    }

private:
    int id_;
    std::string first_name_;
    std::string last_name_;

    // std::vector<Fund> funds_;
    std::vector<Fund> funds_;
};
#endif
