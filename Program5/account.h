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

const static int kFunds = 8;
const static char *kFundsName[kFunds] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond",
                                         "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund"};
class Account
{
public:
    Account();
    Account(int id, std::string last_name, std::string first_name);

    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    void print_account() const;

    bool operator>(const Account &acct) const;

    bool operator<(const Account &acct) const;
    bool operator==(const Account &acct) const;

    void operator=(const Account &rhs);

    // Accessors
    std::string last_name() const;
    std::string first_name() const;
    int id() const;

    // Add to fund
    void Deposit(int fund, int amount);

    void Withdraw(int fund, int amount);

    void WithdrawInsufficientFund(int fund, int amount);

    void AddHistory(int fund, std::string line);
    void PrintFundsHistory() const;
    void PrintFund(int fund) const;

private:
    int id_;
    std::string first_name_;
    std::string last_name_;
    std::vector<Fund> funds_;
};
#endif
