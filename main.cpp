#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstring>
#include "Account_Info.h"
#include "Deposit_Money.h"
#include "Withdraw_Money.h"
#include "modify_account.h"
#include "close_account.h"
#include "showall.h"


using namespace std;

#include "balance_enquiry.h"

int main()
{
    int ch;
    while(1)
    {
        system("cls");
        if(ch==8)
        {
            cout << "\n\n\tThank You For Using ATM & Bank Management System\n\n\t";
            getch();
            break;
        }
        cout << "\t\t\t____________________ATM and Bank Management System_____________________\t\t\t" << endl << endl;
        cout <<"\n\tMAIN MENU";
        cout <<"\n\n\t01. NEW ACCOUNT";
        cout <<"\n\n\t02. DEPOSIT AMOUNT";
        cout <<"\n\n\t03. WITHDRAW AMOUNT";
        cout <<"\n\n\t04. BALANCE ENQUIRY";
        cout <<"\n\n\t05. MODIFY AN ACCOUNT(Profession,Salary,Pin)";
        cout <<"\n\n\t06. CLOSE AN ACCOUNT";
        cout <<"\n\n\t07. SHOW ALL";
        cout <<"\n\n\t08. EXIT";
        cout <<"\n\n\tSelect Your Option (1-8): ";
        cin >> ch;
        cin.ignore();
        system("cls");
        switch(ch)
        {
        case 1:
        {
            Account_Info *ac;
            Deposit_Money dm;
            ac=&dm;
            string hname,hprof,hnationality;
            int hage;
            char htype;
            long long hincome,hnational_id;
            cout << "\n\n\tEnter Your Name: ";
            getline(cin,hname);
            dm.setName(hname);
            cout << "\n\n\tEnter Your Age: ";
            cin >> hage;
            cin.ignore();
            dm.setAge(hage);
            cout << "\n\n\tEnter Your Profession: ";
            getline(cin,hprof);
            dm.setProfession(hprof);
            cout << "\n\n\tEnter Your Account Type('C' for current Account or 'S' for savings Account): ";
            cin >> htype;
            cin.ignore();
            dm.setAccountType(htype);
            cout << "\n\n\tEnter Your Monthly Income: ";
            cin >> hincome;
            dm.setMonthlyIncome(hincome);
            cin.ignore();
            cout << "\n\n\tEnter Your Nationality: ";
            getline(cin,hnationality);
            dm.setNationality(hnationality);
            cout << "\n\n\tEnter Your National ID: ";
            cin >> hnational_id;
            cin.ignore();
            dm.setNationalId(hnational_id);
            system("cls");
            long long Account_Number;
            ifstream fread("AccountNumberCreator.txt");
            fread >> Account_Number;
            fread.close();
            ofstream fwrite("AccountNumberCreator.txt");
            fwrite << Account_Number+1;
            fwrite.close();
            cout << "\n\n\tACCOUNT CREATED SUCCESSFULLY!!!";
            cout << "\n\n\tYour account number is: ";
            cout << Account_Number;
            dm.setAccountNumber(Account_Number);
            getch();
            dm.setPin();
            cout << "\n\n\tPin set successfully!!!";
            getch();
            system("cls");
            string m=dm.getPin();
            ofstream l("Money_Info.txt",ios::out | ios::app);
            l << Account_Number << " " << m << " " << dm.getAccount_Balance() << endl;
            l.close();
            cout << "\n\n\tYou have to deposit at least 500 tk or more to activate your account.";
            getch();
            long long v;
            while(1)
            {
                system("cls");
                cout << "\n\n\tHow much you want to deposit: ";
                cin >> v;
                if(v>=500)
                {
                    dm.setDeposit(v);
                    break;
                }
                else
                {
                    cout << "\n\n\tPlease deposit at least 500 tk or more.";
                    getch();
                }
            }
            ac->Function();
            ofstream fw("AccountInfo.txt",ios::out|ios::app);
            fw << dm.getAccountNumber() << "\n";
            fw << dm.getPin() << "\n";
            fw << dm.getName() << "\n";
            fw << dm.getProfession() << "\n";
            if(dm.getAccountType()=='C' || dm.getAccountType()=='c') fw << "Current Account\n";
            else fw << "Savings Account\n";
            fw << dm.getMonthlyIncome() << "\n";
            fw << dm.getNationality() << "\n";
            fw << dm.getAge() << "\n";
            fw << dm.getNationalId() << "\n";
            fw.close();
            cout << "\n\n\tAccount Activated Successfully!!!";
            getch();
            break;
        }

        case 2:
        {
            Account_Info *ac;
            Deposit_Money dm;
            ac=&dm;
            cout << "\n\n\tHow do much you want to deposit: ";
            long long dpst;
            cin >> dpst;
            cin.ignore();
            dm.setDeposit(dpst);
            ac->Function();
            break;
        }
        case 3:
        {
            Account_Info *ac;
            Withdraw_Money wm;
            ac=&wm;
            cout << "\n\n\tHow much money do you want to Withdraw: ";
            wm.setWithdraw();
            ac->Function();
            break;

        }
        case 4:
        {
            Balance_enquiry::blncEnq();
            break;
        }
        case 5:
        {
            int check;
            cout << "\n\n\t11 UPDATE PROFESSION";
            cout << "\n\n\t12 UPDATE SALARY";
            cout << "\n\n\t13 RESET PIN";
            cout << "\n\n\tSelect Your Option(11-13): ";
            cin >> check;
            cin.ignore();
            if(check==11)
            {
                Modify m;
                m.updateProf();
                system("cls");
                cout << m;
            }
            else if(check==12)
            {
                Modify m;
                m.updateSal();
                system("cls");
                cout << m;
            }
            else
            {
                Modify m;
                m.updatePin();
            }
            break;
        }
        case 6:
        {
            long long n;
            string s;
            cout << "\n\n\tEnter Your Account Number: ";
            cin >> n;
            cin.ignore();
            cout << "\n\n\tEnter Your Pin: ";
            getline(cin,s);
            int len=s.length();
            close_acnt c(len,s);
            c.closeAccount(n);
            break;
        }
        case 7:
        {
            show <Deposit_Money> s;
            s.readFile();
            s.showFile();
            getch();
            break;
        }


        }
    }
    return 0;
}
