#include "close_account.h"

close_acnt::close_acnt(int length,string s)
{
    int i;
    pin=new char[length+1];
    for(i=0;i<length;i++)
    {
        pin[i]=s[i];
    }
    pin[i]='\0';
}

close_acnt::~close_acnt()
{
    delete [] pin;
}

void close_acnt::closeAccount(long long n)
{
    int flag=0;
    account_number=n;
    long long ac,money;
    string dummy;
    string hname,hprof,hnationality;
    int hage;
    string htype;
    long long hincome,hnational_id;
    ifstream fin1("AccountInfo.txt");
    ifstream fin2("Money_Info.txt");
    ofstream fout1("temp.txt");
    ofstream fout2("temp2.txt");
    while(fin2 >> ac >> dummy >> money)
    {
        fin1 >> ac;
        fin1.ignore();
        getline(fin1,dummy);
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
        if(ac==account_number && strcmp(dummy.c_str(),pin)==0)
        {
            flag=1;
            if(money>500)
            {
                cout << "\n\n\tYou have " << money << " tk in your account.";getch();
                cout << "\n\n\tYou can collect " << money-500 << " tk from your account.";getch();
                cout << "\n\n\tPlease Collect the Cash.";
                getch();
            }
            else
            {
                cout << "\n\n\tYou have " << money << " tk in your account.";getch();
                cout << "\n\n\tThis is CAUTION MONEY and so You can not collect it.";
                getch();
            }
            continue;
        }
        else
        {
            fout1 << ac << "\n";
            fout1 << dummy << "\n";
            fout1 << hname << "\n";
            fout1 << hprof << "\n";
            fout1 << htype << "\n";
            fout1 << hincome << "\n";
            fout1 << hnationality << "\n";
            fout1 << hage << "\n";
            fout1 << hnational_id << "\n";
            fout2 << ac << " " << dummy << " " << money << endl;
        }

    }
    fin1.close();
    fin2.close();
    fout1.close();
    fout2.close();
    if(flag==0)
    {
        cout << "\n\n\tEither this account does not exist or wrong pin.please try again.";
        getch();
        ofstream z("temp.txt");
        ofstream y("temp2.txt");
        z.close();
        y.close();
        return;
    }
    ofstream d("AccountInfo.txt");
    ofstream c("Money_Info.txt");
    ifstream b("temp.txt");
    ifstream e("temp2.txt");
    while(e >> ac >> dummy >> money)
    {
        b >> ac;
        b.ignore();
        getline(b,dummy);
        getline(b,hname);
        getline(b,hprof);
        getline(b,htype);
        b >> hincome;
        b.ignore();
        getline(b,hnationality);
        b >> hage;
        b.ignore();
        b >> hnational_id;
        b.ignore();
        d << ac << "\n";
        d << dummy << "\n";
        d << hname << "\n";
        d << hprof << "\n";
        d << htype << "\n";
        d << hincome << "\n";
        d << hnationality << "\n";
        d << hage << "\n";
        d << hnational_id << "\n";
        c << ac << " " << dummy << " " << money << endl;
    }
    d.close();
    c.close();
    b.close();
    e.close();
    ofstream j("temp.txt");
    ofstream k("temp2.txt");
    j.close();
    k.close();
    cout << "\n\n\tAccount Closed Successfully.";
    getch();


}
