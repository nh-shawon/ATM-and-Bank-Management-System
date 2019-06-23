
#include <iostream>
#include <cstring>
#include <conio.h>
#include <fstream>

#include "balance_enquiry.h"

using namespace std;

void Balance_enquiry::blncEnq()
{
    long long acnum1,acnum2;
    char pin1[16],pin2[16];
    long long money;
    int flag=0;
    cout << "\n\n\tEnter your account number: ";
    cin >> acnum1;
    cin.ignore();
    cout << "\n\n\tPlease Enter Your Pin: ";
    char a;
    for(int i=0;;)
    {
        a=getch();
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        {
            pin1[i]=a;
            cout << "*";
            i++;
        }
        if(a=='\b' && a>=1)
        {
            cout << "\b \b";
            i--;
        }
        if(a=='\r')
        {
            pin1[i]='\0';
            break;
        }
    }
    ifstream fread("Money_Info.txt");
    while(fread >> acnum2 >> pin2 >> money)
    {
        if(acnum1==acnum2 && strcmp(pin1,pin2)==0)
        {
            cout << "\n\n\tYour Account Balance is " << money;
            getch();
            flag=1;
        }
    }
    fread.close();
    if(flag==0)
    {
        cout << "\n\n\tWrong Account Number or Wrong Pin.";
        getch();
    }
}

