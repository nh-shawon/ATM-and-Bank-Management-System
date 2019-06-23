#include "Withdraw_Money.h"

Withdraw_Money::Withdraw_Money()
{
    //ctor
}

Withdraw_Money::~Withdraw_Money()
{
    //dtor
}

void Withdraw_Money::setWithdraw()
{
    cin >> withdraw;
    cin.ignore();
}

void Withdraw_Money::Function()
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
    int flag=0,flag1=0;
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
            if((money-withdraw)<500)
            {
                cout << "\n\n\tInsufficient Balance.";
                cout << "\n\n\tYou always need to keep at least 500 tk in your account.";
                cout << "\n\n\tIf you withdraw,your balance will be " << money-withdraw;
                y << Account_Number1 << " " << p1 << " " << money << endl;
                flag1=1;
            }
            else
            {
                y << Account_Number1 << " " << p1 << " " << money-withdraw << endl;
                flag=1;
            }
        }
        else
        {
            y << Account_Number1 << " " << p1 << " " << money << endl;
        }
    }
    x.close();
    y.close();
    if(flag==0 && flag1==0)
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
    if(flag==1) cout << "\n\n\tMoney Withdrawn Successfully.Please collect your cash.";
    else cout << "\n\n\tMoney Withdrawn Failed.Please Try Again.";
    getch();

}
