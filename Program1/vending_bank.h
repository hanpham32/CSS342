#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

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

        void setPenny(int penny);
        void setNickel(int nickle);
        void setDime(int dime);
        void setQuarter(int quarter);

        void DepositPenny(int penny);
        void DepositNickel(int nickel);
        void DepositDime(int dime);
        void DepositQuarter(int quarter);


    private:
        int id_;
        int penny_;
        int nickel_;
        int dime_;
        int quarter_;
        
};
#endif