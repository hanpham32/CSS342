#include "account.h"

Account::Account() : id_(0), last_name_(""), first_name_("") {}

Account::Account(int id, std::string last_name, std::string first_name) : id_(id), last_name_(last_name), first_name_(first_name)
{
    for (int i = 0; i < kFunds; i++)
    {
        Fund f;
        funds_.push_back(f);
    }
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << account.first_name_ << account.last_name_ << "Account ID: " << account.id_ << std::endl;
    return os;
}

void Account::print_account() const
{
    std::cout << last_name() << " " << first_name() << " "
              << "Account ID: " << id() << std::endl;
    for (int i = 0; i < kFunds; i++)
    {
        std::cout << "     " << kFundsName[i] << ": $" << funds_[i].balance() << std::endl;
    }
}

bool Account::operator>(const Account &acct) const
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

bool Account::operator<(const Account &acct) const
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

bool Account::operator==(const Account &acct) const
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

void Account::operator=(const Account &rhs)
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
std::string Account::last_name() const { return last_name_; }
std::string Account::first_name() const { return first_name_; }
int Account::id() const { return id_; }

// Add to fund
void Account::Deposit(int fund, int amount)
{
    funds_[fund].Deposit(amount);
}

void Account::Withdraw(int fund, int amount)
{
    // check if fund has sufficient balance
    if (funds_[fund].balance() >= amount)
    {
        funds_[fund].Withdraw(amount);
    }
    else
    {
        WithdrawInsufficientFund(fund, amount);
    }
}

void Account::WithdrawInsufficientFund(int fund, int amount)
{
    switch (fund)
    {
    case 0:
    {
        if (funds_[0].balance() + funds_[1].balance() >= amount)
        {
            int remained = amount - funds_[0].balance();
            funds_[0].clear();
            funds_[1].Withdraw(remained);
        }
        break;
    }
    case 1:
    {
        if (funds_[0].balance() + funds_[1].balance() >= amount)
        {
            int remained = amount - funds_[1].balance();
            funds_[1].clear();
            funds_[0].Withdraw(remained);
        }
        break;
    }
    case 2:
    {
        if (funds_[2].balance() + funds_[3].balance() >= amount)
        {
            int remained = amount - funds_[2].balance();
            funds_[2].clear();
            funds_[3].Withdraw(remained);
        }
        break;
    }
    case 3:
    {
        if (funds_[2].balance() + funds_[3].balance() >= amount)
        {
            int remained = amount - funds_[3].balance();
            funds_[3].clear();
            funds_[2].Withdraw(remained);
        }
        break;
    }
    default:
    {
        std::cout << "ERROR:: Insufficient Balance" << std::endl;
    }
    }
}

void Account::AddHistory(int fund, std::string line)
{
    funds_[fund].AddHistory(line);
}
void Account::PrintFundsHistory() const
{
    std::cout << "Transaction History for " << first_name() << " " << last_name() << " by fund." << std::endl;
    for (int i = 0; i < kFunds; i++)
    {
        std::cout << kFundsName[i] << ": $" << funds_[i].balance() << std::endl;
        funds_[i].PrintAllHistory();
    }
}
void Account::PrintFund(int fund) const
{
    std::cout << "Transaction History for " << first_name() << " " << last_name() << " " << kFundsName[fund] << ": $" << funds_[fund].balance() << std::endl;
    funds_[fund].PrintAllHistory();
}