#ifndef WITHDRAW_MONEY_H
#define WITHDRAW_MONEY_H

#include <Account_Info.h>
#include<iostream>
#include <fstream>
#include<cstring>



class Withdraw_Money : public Account_Info
{
    public:
        Withdraw_Money();
        virtual ~Withdraw_Money();
        void setWithdraw();
        void Function();

    protected:

    private:
        long long withdraw;
};

#endif // WITHDRAW_MONEY_H

