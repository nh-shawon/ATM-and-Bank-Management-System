#ifndef SHOWALL_H_INCLUDED
#define SHOWALL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Deposit_Money.h>

using namespace std;

template <typename T>

class show
{
public:
    vector <T> vec;
    void readFile()
    {
        ifstream fin1("AccountInfo.txt");
        ifstream fin2("Money_Info.txt");
        long long accnum,money;
        string pin;
        string hname,hprof,hnationality;
        int hage;
        string htype;
        long long hincome,hnational_id;
        while(fin2 >> accnum >> pin >> money)
        {
            T dm;
            fin1 >> accnum;
            fin1.ignore();
            getline(fin1,pin);
            getline(fin1,hname);
            getline(fin1,hprof);
            getline(fin1,htype);
            fin1 >> hincome;
            fin1.ignore();
            getline(fin1,hnationality);
            fin1 >> hage;
            fin1.ignore();
            fin1 >> hnational_id;
            fin1.ignore();
            dm.setAccountNumber(accnum);
            dm.setName(hname);
            dm.setAccount_Balance(money);
            vec.push_back(dm);

        }
        fin1.close();
        fin2.close();

    }

    void showFile()
    {
        sort(vec.begin(),vec.end(),[](T t1,T t2){return t1.getAccount_Balance()>t2.getAccount_Balance();});
        int i;
        cout << setw(10) << "AC.NUMBER" << setw(35) << "NAME " << setw(25) << "AC.BALANCE";
        for(i=0;i<vec.size();i++)
        {
             cout << "\n\n " << vec[i].getAccountNumber() << " " << setw(40) << vec[i].getName() << " " << setw(15) << vec[i].getAccount_Balance();
        }
    }

};


#endif // SHOWALL_H_INCLUDED
