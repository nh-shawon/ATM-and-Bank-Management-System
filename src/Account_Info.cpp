#include "Account_Info.h"

Account_Info::Account_Info()
{
    //ctor
}

Account_Info::~Account_Info()
{
    //dtor
}

void Account_Info::setName(string s)
{
    //name=new char[100];
    name=s;
}

string Account_Info::getName()
{
    return name;
}

void Account_Info::setProfession(string s)
{
   // profession=new char[30];
    profession=s;
}

string Account_Info::getProfession()
{
    return profession;
}

void Account_Info::setMonthlyIncome(long long n)
{
    monthly_income=n;
}

long long Account_Info::getMonthlyIncome()
{
    return monthly_income;
}

void Account_Info::setNationality(string s)
{
    //nationality=new char[20];
    nationality=s;
}

string Account_Info::getNationality()
{
    return nationality;
}

void Account_Info::setAge(int n)
{
    age=n;
}

int Account_Info::getAge()
{
    return age;
}

void Account_Info::setNationalId(long long n)
{
    national_id=n;
}

long long Account_Info::getNationalId()
{
    return national_id;
}

void Account_Info::setPin()
{
    char a;int i,j;
    char check[16];
    START:
    system("cls");
    cout << "\n\n\tPlease Enter Your pin(4-15): ";
    for(i=0;;)
    {
        a=getch();
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        {
            pin[i]=a;
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
            pin[i]='\0';
            break;
        }
    }
    if(i<4)
    {
        cout << "\n\n\tToo Short!!! Please try again";
        getch();
        goto START;
    }
    cout << "\n\n\tPlease Re-enter Your pin(4-15): ";
    for(j=0;;)
    {
        a=getch();
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        {
            check[j]=a;
            cout << "*";
            j++;
        }
        if(a=='\b' && a>=1)
        {
            cout << "\b \b";
            j--;
        }
        if(a=='\r')
        {
            check[j]='\0';
            break;
        }
    }
    int res=strcmp(pin,check);
    if(res!=0)
    {
        cout << "\n\n\tWrong Password.Please Try Again.";
        getch();
        goto START;
    }
}

string Account_Info::getPin()
{
    return pin;
}

void Account_Info::Function()
{

}

void Account_Info::setAccountType(char c)
{
    account_type=c;
}

char Account_Info::getAccountType()
{
    return account_type;
}

void Account_Info::setAccountNumber(long long n)
{
    account_number=n;
}

long long Account_Info::getAccountNumber()
{
    return account_number;
}

void Account_Info::cpyPin(string p)
{
    int i=0;
    while(1)
    {
        if(p[i]=='\0')
        {
            pin[i]='\0';
            break;
        }
        else
        {
            pin[i]=p[i];
            i++;
        }
    }
}
