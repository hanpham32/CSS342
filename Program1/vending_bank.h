#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

class VendingBank
{
    public:
        VendingBank();
        VendingBank(int id);

        //getters-setters
        int id() const;

    private:
        int id_;
        
};
#endif