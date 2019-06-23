#ifndef CLOSE_ACCOUNT_H_INCLUDED
#define CLOSE_ACCOUNT_H_INCLUDED


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <cstring>

using namespace std;

class close_acnt
{
private:
    long long account_number;
    char *pin;

public:
    void closeAccount(long long n);
    close_acnt(int length,string s);
    ~close_acnt();

};

#endif // CLOSE_ACCOUNT_H_INCLUDED
