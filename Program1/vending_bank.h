#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

#include <iostream>
using namespace std;

class VendingBank
{
public:
    VendingBank();
    VendingBank(int id);

    // getters-setters
    int id() const;
    int penny() const;
    int nickel() const;
    int dime() const;
    int quarter() const;
    int halve() const;

    int getTotalMoney() const;

    void set_penny(int penny);
    void set_nickel(int nickle);
    void set_dime(int dime);
    void set_quarter(int quarter);
    void set_halve(int halve);

    void DepositPenny(int penny);
    void DepositNickel(int nickel);
    void DepositDime(int dime);
    void DepositQuarter(int quarter);
    void DepositHalve(int halve);

    void WithdrawPenny(int penny);
    void WithdrawNickel(int nickel);
    void WithdrawDime(int dime);
    void WithdrawQuarter(int quarter);
    void WithdrawHalve(int halve);

    bool isEmpty() const;
    bool isTransactionSuccessful() const;

    friend ostream &operator<<(ostream &os, const VendingBank &vb);
    bool operator==(const VendingBank &vb) const;
    bool operator!=(const VendingBank &vb) const;

private:
    int id_;
    int penny_;
    int nickel_;
    int dime_;
    int quarter_;
    int halve_;
};
#endif