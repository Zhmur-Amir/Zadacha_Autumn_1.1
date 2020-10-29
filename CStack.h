#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include "CStack2.h"
#include <fstream>
using namespace std;
#define L 5


class CStack
{
    int n,size1,size2,size3; string *s;;
public:
    CStack()=delete;
    CStack(int b)
    {SetZero();
    size3=b;
    s=new string[size1=L];
    }
    void SetZero(){s=NULL; n=size1=size2=0;}
    CStack(const CStack&b){CopyOnly(b);}
    void CopyOnly(const CStack&b)
    {n=b.n;
    size2=b.size2;
     size3=b.size3;
     s=new string[size1=b.size1];
     for(int i=0;i<n;i++)
        {s[i]=b.s[i];}
     }
    void Clean(){delete[] s; SetZero();}
    ~CStack(){Clean();}
    CStack &operator=(const CStack&b)
    {if(this!=&b)
    {Clean(); CopyOnly(b);}
    return *this;
    }
    int IsEmpty(){return n==0;}
    int IsFilled(){return n==size1;}
    int IsMemory(){return size2>size3;}
    int GetTop(string&x)
    {
        if(IsEmpty())
            return -1;
        x=s[n-1];
        return 0;
    }
    int Memory(){return size2;}
    int FullMemory(){return size3;}
    int PushTop(const string&x)
    {
        size2=size2+x.length();
        if(IsMemory())
        {
           size2=size2-x.length();
           return -2;
        }

        if(IsFilled())
        {
            string *w=new string[size1=size1*2+1];
            for(int i=0;i<n;i++)
                {
                    w[i]=s[i];
                }
            delete[] s;
            s=w;
        }
        s[n++]=x;
        return 0;
    }
    int DelTop()
    {
        if(IsEmpty())
            {return -1;}
        int k;
        k=LenTop();
        size2=size2-k;
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
    int Push(const string&x,  CStack2 &h, const char* filename);
    int Del( CStack2 &r, const char* filename);
    int Get(string&x, CStack2 &r, const char* filename);
};


void Autotest(void);
void vvod(CStack&c, CStack2 &r, const char* filename);










