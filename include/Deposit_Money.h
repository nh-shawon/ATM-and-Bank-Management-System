#ifndef DEPOSIT_MONEY_H
#define DEPOSIT_MONEY_H

#include <Account_Info.h>
#include<iostream>
#include <fstream>
#include<cstring>

class Deposit_Money : public Account_Info
{
    public:
        Deposit_Money();
        Deposit_Money(long long x);
        virtual ~Deposit_Money();
        void setDeposit(long long x);
        long long getAccount_Balance();
        void setAccount_Balance(long long n);
        void Function();

    protected:

    private:
        long long Account_Balance;
        long long deposit;

};

#endif // DEPOSIT_MONEY_H
