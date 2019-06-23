#ifndef MODIFY_ACCOUNT_H_INCLUDED
#define MODIFY_ACCOUNT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <cstring>
#include <Deposit_Money.h>

using namespace std;

class Modify : public Deposit_Money
{
public:
    void updateProf();
    void updateSal();
    void updatePin();
    friend ostream& operator<<(ostream &output,Modify p);
};

#endif // MODIFY_ACCOUNT_H_INCLUDED
