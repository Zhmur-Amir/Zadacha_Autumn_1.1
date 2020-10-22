#pragma once
#include <math.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
#define N 3


class CStack
{
    int n; string s[N];
public:
    CStack(){n=0;}
    void Clean(){n=0;}
    int IsEmpty(){return n==0;}
    int IsFilled(){return n==N;}
    int GetTop(string&x)
    {
        if(IsEmpty())
            return -1;
        x=s[n-1];
        return 0;
    }

    int PushTop(const string&x)
    {
        if(IsFilled())
            return -2;
        s[n++]=x;
        return 0;
    }
    int DelTop()
    {
        if(IsEmpty())
            return -1;
        n--;
         return 0;
    }
    int Length(){return n;}
    int LenTop()
    {
        if(IsEmpty())
            return 0;
        return s[n-1].length();
    }
    void print()
    {
        for(int i=0;i<n;i++)
            {cout<<s[i]<<endl;}
        }
    string &operator[](int i)
    {
        if(i<0 || i>=n)
            throw 3;
        return s[i];
    }
};

int Push(const string&x, CStack &c, const char* filename);
int Del(CStack &c, const char* filename);
int Get(string&x, CStack &c,const char* filename);
void Autotest(void);
void vvod(CStack&c, const char* filename);










