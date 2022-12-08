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

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account
{
public:
    friend std::ostream &operator<<(std::ostream &os, const Account &account)
    {
        os << account.id_ << " " << account.last_name_ << " " << account.first_name_ << std::endl;
    }

private:
    int id_;
    std::string first_name_;
    std::string last_name_;
};
#endif
