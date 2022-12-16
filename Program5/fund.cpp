#include "fund.h"

Fund::Fund() : balance_(0) {}

void Fund::Deposit(int amount)
{
    balance_ += amount;
}

void Fund::Withdraw(int amount)
{
    balance_ -= amount;
}

void Fund::Transfer(Fund &to, int amount)
{
    balance_ -= amount;
    to.balance_ += amount;
}

int Fund::balance() const
{
    return balance_;
}
void Fund::clear()
{
    balance_ = 0;
}

void Fund::AddHistory(std::string line)
{
    history_.push_back(line);
}

void Fund::PrintAllHistory() const
{
    for (int i = 0; i < history_.size(); i++)
    {
        std::cout << history_[i] << std::endl;
    }
}