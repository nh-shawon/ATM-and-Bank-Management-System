#include "modify_account.h"

void Modify::updateProf()
{
    system("cls");
    long long an;string pin1,pin2;
    string uprof;
    cout << "\n\n\tEnter Your account number: ";
    cin >> an;
    cin.ignore();
    cout << "\n\n\tPlease Enter Your Pin: ";
    char a;
    int flag=0;
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
    string hname,hprof,hnationality,htype;
    int hage;
    long long hincome,hnational_id,accnum;
    ifstream fin("AccountInfo.txt");
    ofstream fout("temp.txt");
    ifstream mo("Money_Info.txt");
    long long ac,money;
    char dummy[16];
    while(mo >> ac >> dummy >> money)
    {
        fin >> accnum;
        fin.ignore();
        getline(fin,pin2);
        getline(fin,hname);
        getline(fin,hprof);
        getline(fin,htype);
        fin >> hincome;
        fin.ignore();
        getline(fin,hnationality);
        fin >> hage;
        fin.ignore();
        fin >> hnational_id;
        fin.ignore();
        if(accnum==an && strcmp(pin1.c_str(),pin2.c_str())==0)
        {
            flag=1;
            cout << "\n\n\tEnter your Profession: ";
            getline(cin,uprof);
            setProfession(uprof);
            setAccountNumber(accnum);
            cpyPin(pin2);
            setName(hname);
            if(htype[0]=='S') setAccountType('S');
            else setAccountType('C');
            setMonthlyIncome(hincome);
            setNationality(hnationality);
            setAge(hage);
            setNationalId(hnational_id);
            fout << getAccountNumber() << "\n";
            fout << getPin() << "\n";
            fout << getName() << "\n";
            fout << getProfession() << "\n";
            if(getAccountType()=='C' || getAccountType()=='c') fout << "Current Account\n";
            else fout << "Savings Account\n";
            fout << getMonthlyIncome() << "\n";
            fout << getNationality() << "\n";
            fout << getAge() << "\n";
            fout << getNationalId() << "\n";
        }
        else
        {
            fout << accnum << "\n";
            fout << pin2 << "\n";
            fout << hname << "\n";
            fout << hprof << "\n";
            fout << htype << "\n";
            fout << hincome << "\n";
            fout << hnationality << "\n";
            fout << hage << "\n";
            fout << hnational_id << "\n";
        }

    }
    fin.close();
    fout.close();
    mo.close();
    if(flag==0)
    {
        cout << "\n\n\tWrong Account Number or Pin.Try again.";
        getch();
        ofstream u("temp.txt");
        u.close();
        return;
    }
    ofstream n("AccountInfo.txt");
    n.close();
    ifstream b("temp.txt");
    ofstream c("AccountInfo.txt");
    ifstream mo1("Money_Info.txt");
    while(mo1 >> ac >> dummy >> money)
    {
        b >> accnum;
        b.ignore();
        getline(b,pin2);
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
        c << accnum << "\n";
        c << pin2 << "\n";
        c << hname << "\n";
        c << hprof << "\n";
        c << htype << "\n";
        c << hincome << "\n";
        c << hnationality << "\n";
        c << hage << "\n";
        c << hnational_id << "\n";

    }
    b.close();
    c.close();
    mo1.close();
    ofstream e("temp.txt");
    e.close();
    cout << "\n\n\tUpdated Successfully!!!";
    getch();
    cout << "\n\n\tAfter Updating....";
    getch();

}

void Modify::updateSal()
{
    system("cls");
    long long an;string pin1,pin2;
    long long usal;
    cout << "\n\n\tEnter Your account number: ";
    cin >> an;
    cin.ignore();
    cout << "\n\n\tPlease Enter Your Pin: ";
    char a;
    int flag=0;
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
    string hname,hprof,hnationality,htype;
    int hage;
    long long hincome,hnational_id,accnum;
    ifstream fin("AccountInfo.txt");
    ofstream fout("temp.txt");
    long long ac,money;
    char dummy[16];
    ifstream mo("Money_Info.txt");
    while(mo >> ac >> dummy >> money)
    {
        fin >> accnum;fin.ignore();
        getline(fin,pin2);
        getline(fin,hname);
        getline(fin,hprof);
        getline(fin,htype);
        fin >> hincome;fin.ignore();
        getline(fin,hnationality);
        fin >> hage;fin.ignore();
        fin >> hnational_id;fin.ignore();
        if(accnum==an && strcmp(pin1.c_str(),pin2.c_str())==0)
        {
            flag=1;
            cout << "\n\n\tEnter your Salary: ";
            cin >> usal;
            cin.ignore();
            setMonthlyIncome(usal);
            setAccountNumber(accnum);
            cpyPin(pin2);
            setName(hname);
            if(htype[0]=='S') setAccountType('S');
            else setAccountType('C');
            setProfession(hprof);
            setNationality(hnationality);
            setAge(hage);
            setNationalId(hnational_id);
            fout << getAccountNumber() << "\n";
            fout << getPin() << "\n";
            fout << getName() << "\n";
            fout << getProfession() << "\n";
            if(getAccountType()=='C' || getAccountType()=='c') fout << "Current Account\n";
            else fout << "Savings Account\n";
            fout << getMonthlyIncome() << "\n";
            fout << getNationality() << "\n";
            fout << getAge() << "\n";
            fout << getNationalId() << "\n";
        }
        else
        {
            fout << accnum << "\n";
            fout << pin2 << "\n";
            fout << hname << "\n";
            fout << hprof << "\n";
            fout << htype << "\n";
            fout << hincome << "\n";
            fout << hnationality << "\n";
            fout << hage << "\n";
            fout << hnational_id << "\n";
        }

    }
    fin.close();
    fout.close();
    mo.close();
    if(flag==0)
    {
        cout << "\n\n\tWrong Account Number or Pin.Try again.";
        getch();
        ofstream u("temp.txt");
        u.close();
        return;
    }
    ofstream n("AccountInfo.txt");
    n.close();
    ifstream b("temp.txt");
    ofstream c("AccountInfo.txt");
    ifstream mo1("Money_Info.txt");
    while(mo1 >> ac >> dummy >> money)
    {
        b >> accnum;b.ignore();
        getline(b,pin2);
        getline(b,hname);
        getline(b,hprof);
        getline(b,htype);
        b >> hincome;b.ignore();
        getline(b,hnationality);
        b >> hage;b.ignore();
        b >> hnational_id;b.ignore();
        c << accnum << "\n";
        c << pin2 << "\n";
        c << hname << "\n";
        c << hprof << "\n";
        c << htype << "\n";
        c << hincome << "\n";
        c << hnationality << "\n";
        c << hage << "\n";
        c << hnational_id << "\n";

    }
    b.close();
    c.close();
    mo1.close();
    ofstream e("temp.txt");
    e.close();
    cout << "\n\n\tUpdated Successfully!!!";
    getch();
    cout << "\n\n\tAfter Updating....";
    getch();
}

void Modify::updatePin()
{
    system("cls");
    long long an;string pin1,pin2;
    cout << "\n\n\tEnter Your account number: ";
    cin >> an;
    cin.ignore();
    cout << "\n\n\tPlease Enter Your Old Pin: ";
    char a;
    int flag=0;
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
    string hname,hprof,hnationality,htype;
    int hage;
    long long hincome,hnational_id,accnum;
    long long money;
    string dummy;
    ifstream fin1("AccountInfo.txt");
    ifstream fin2("Money_Info.txt");
    ofstream fout1("temp.txt");
    ofstream fout2("temp2.txt");
    while(fin2 >> accnum >> dummy >> money)
    {
        fin1 >> accnum;fin1.ignore();
        getline(fin1,pin2);
        getline(fin1,hname);
        getline(fin1,hprof);
        getline(fin1,htype);
        fin1 >> hincome;fin1.ignore();
        getline(fin1,hnationality);
        fin1 >> hage;fin1.ignore();
        fin1 >> hnational_id;fin1.ignore();
        if(accnum==an && strcmp(pin1.c_str(),pin2.c_str())==0)
        {
            flag=1;
            setPin();
            setProfession(hprof);
            setAccountNumber(accnum);
            setName(hname);
            if(htype[0]=='S') setAccountType('S');
            else setAccountType('C');
            setMonthlyIncome(hincome);
            setNationality(hnationality);
            setAge(hage);
            setNationalId(hnational_id);
            fout1 << getAccountNumber() << "\n";
            fout1 << getPin() << "\n";
            fout1 << getName() << "\n";
            fout1 << getProfession() << "\n";
            if(getAccountType()=='C' || getAccountType()=='c') fout1 << "Current Account\n";
            else fout1 << "Savings Account\n";
            fout1 << getMonthlyIncome() << "\n";
            fout1 << getNationality() << "\n";
            fout1 << getAge() << "\n";
            fout1 << getNationalId() << "\n";
            fout2 << accnum << " " << getPin() << " " << money << endl;
        }
        else
        {
            fout1 << accnum << "\n";
            fout1 << pin2 << "\n";
            fout1 << hname << "\n";
            fout1 << hprof << "\n";
            fout1 << htype << "\n";
            fout1 << hincome << "\n";
            fout1 << hnationality << "\n";
            fout1 << hage << "\n";
            fout1 << hnational_id << "\n";
            fout2 << accnum << " " << dummy << " " << money << endl;
        }

    }
    fin1.close();
    fin2.close();
    fout1.close();
    fout2.close();
    if(flag==0)
    {
        cout << "\n\n\tWrong Account Number or Pin.Try again.";
        getch();
        ofstream u("temp.txt");
        u.close();
        ofstream j("temp2.txt");
        j.close();
        return;
    }
    ofstream n("AccountInfo.txt");
    n.close();
    ofstream z("Money_Info.txt");
    z.close();
    ifstream b("temp.txt");
    ifstream x("temp2.txt");
    ofstream c("AccountInfo.txt");
    ofstream y("Money_Info.txt");
    while(x >> accnum >> dummy >> money)
    {
        b >> accnum;b.ignore();
        getline(b,pin2);
        getline(b,hname);
        getline(b,hprof);
        getline(b,htype);
        b >> hincome;b.ignore();
        getline(b,hnationality);
        b >> hage;b.ignore();
        b >> hnational_id;b.ignore();
        c << accnum << "\n";
        c << pin2 << "\n";
        c << hname << "\n";
        c << hprof << "\n";
        c << htype << "\n";
        c << hincome << "\n";
        c << hnationality << "\n";
        c << hage << "\n";
        c << hnational_id << "\n";
        y << accnum << " " << dummy << " " << money << endl;;

    }
    b.close();
    c.close();
    x.close();
    y.close();
    ofstream e("temp.txt");
    ofstream w("temp2.txt");
    e.close();
    w.close();
    cout << "\n\n\tPin Updated Successfully!!!";
    getch();

}

ostream& operator<<(ostream &output,Modify p)
{
    output << "\n\n\tAccount Number: " << p.getAccountNumber();
    output << "\n\n\tName: " << p.getName();
    output << "\n\n\tProfession: " << p.getProfession();
    if(p.getAccountType()=='S')
    {
        output << "\n\n\tAccount Type: Savings Account.";
    }
    else
    {
        output << "\n\n\tAccount Type: Current Account.";
    }
    output << "\n\n\tMonthly Income: " << p.getMonthlyIncome();
    output << "\n\n\tNationality: " << p.getNationality();
    output << "\n\n\tAge: " << p.getAge();
    output << "\n\n\tNational ID: " << p.getNationalId();
    getch();
    return output;
}
