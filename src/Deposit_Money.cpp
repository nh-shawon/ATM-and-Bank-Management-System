#include "Deposit_Money.h"

Deposit_Money::Deposit_Money()
{
    //ctor
    Account_Balance=0;
}

Deposit_Money::~Deposit_Money()
{
    //dtor
}

Deposit_Money::Deposit_Money(long long x)
{
    deposit=x;
}

void Deposit_Money::setDeposit(long long x)
{
    deposit=x;
}

void Deposit_Money::Function()
{
    ifstream x("Money_Info.txt");
    ofstream y("temp.txt");
    long long Account_Number1,Account_Number2;
    char p1[16],p2[16];
    long long money;
    cout << "\n\n\tPlease Enter Your Account Number: ";
    cin >> Account_Number2;
    cout << "\n\n\tPlease Enter Your Pin: ";
    char a;
    int flag=0;
    for(int i=0;;)
    {
        a=getch();
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        {
            p2[i]=a;
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
            p2[i]='\0';
            break;
        }
    }
    while(x >> Account_Number1 >> p1 >> money)
    {
        if(Account_Number1==Account_Number2 && strcmp(p1,p2)==0)
        {
            Account_Balance=deposit+money;
            y << Account_Number1 << " " << p1 << " " << Account_Balance << endl;
            flag=1;
        }
        else
        {
            y << Account_Number1 << " " << p1 << " " << money << endl;
        }
    }
    x.close();
    y.close();
    if(flag==0)
    {
        cout << "\n\n\tWrong Account Number Or Wrong Pin.Please Try Again.";
        getch();
        ofstream u("temp.txt");
        u.close();
        return;
    }
    ofstream e("Money_Info.txt");
    e.close();
    ofstream b("Money_Info.txt");
    ifstream c("temp.txt");
    while(c >> Account_Number1 >> p1 >> money)
    {
        b << Account_Number1 << " " << p1 << " " << money << endl;
    }
    c.close();
    b.close();
    ofstream d("temp.txt");
    d.close();
    cout << "\n\n\tMoney Deposited Successfully.";
    getch();

}

long long Deposit_Money::getAccount_Balance()
{
    return Account_Balance;
}

void Deposit_Money::setAccount_Balance(long long n)
{
    Account_Balance=n;
}
