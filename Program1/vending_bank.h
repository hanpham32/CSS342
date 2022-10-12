#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

#include <iostream>
using namespace std;

class VendingBank
{
    public:
        VendingBank();
        VendingBank(int id);

        //getters-setters
        int id() const;
        int getTotalPenny() const;
        int getTotalNickel() const;
        int getTotalDime() const;
        int getTotalQuarter() const;
        int getTotalMoney() const;

        void DepositPenny(int penny);
        void DepositNickel(int nickel);
        void DepositDime(int dime);
        void DepositQuarter(int quarter);

        void WithdrawPenny(int penny);
        void WithdrawNickel(int nickel);
        void WithdrawDime(int dime);
        void WithdrawQuarter(int quarter);
        
        friend ostream& operator<<(ostream& os, const VendingBank& vb);
        bool operator==(const VendingBank& vb) const;
        bool operator!=(const VendingBank& vb) const;

    private:
        int id_;
        int penny_;
        int nickel_;
        int dime_;
        int quarter_;

        void setPenny(int penny);
        void setNickel(int nickle);
        void setDime(int dime);
        void setQuarter(int quarter);
};
#endif