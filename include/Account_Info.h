#ifndef ACCOUNT_INFO_H
#define ACCOUNT_INFO_H
#include<iostream>
#include<string>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Account_Info
{
    public:
        Account_Info();
        virtual ~Account_Info();
        string getName();
        void setName(string s);
        void setProfession(string s);
        string getProfession();
        long long getMonthlyIncome();
        void setMonthlyIncome(long long n);
        void setNationality(string s);
        string getNationality();
        void setAge(int n);
        int  getAge();
        void setNationalId(long long n);
        long long getNationalId();
        void setPin();
        string getPin();
        void setAccountType(char c);
        char getAccountType();
        void setAccountNumber(long long n);
        long long getAccountNumber();
        void cpyPin(string p);
        virtual void Function();

    protected:

    private:
        string name;
        string profession;
        long long monthly_income;
        string nationality;
        int age;
        long long national_id;
        char pin[16];
        char account_type;
        long long account_number;
};

#endif // ACCOUNT_INFO_H
