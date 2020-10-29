#pragma once
#include "CStack.h"
#define L 5



class CStack2
{
    int n,size1; int *s;;
public:
    CStack2()
    {SetZero();
    s=new int[size1=L];
    }
    void SetZero(){s=NULL; n=size1=0;}
    CStack2(const CStack2&b){CopyOnly(b);}
    void CopyOnly(const CStack2&b)
    {n=b.n;
     s=new int[size1=b.size1];
     for(int i=0;i<n;i++)
        {s[i]=b.s[i];}
     }
    void Clean(){delete[] s; SetZero();}
    ~CStack2(){Clean();}
    CStack2 &operator=(const CStack2&b)
    {if(this!=&b)
    {Clean(); CopyOnly(b);}
    return *this;
    }
    int IsEmpty(){return n==0;}
    int IsFilled(){return n==size1;}
    int GetTop()
    {
        if(IsEmpty())
            return 0;
        int x;
        x=s[n-1];
        return x;
    }
    int PushTop(const int x)
    {
        if(IsFilled())
        {
            int *w=new int[size1=size1*2+1];
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
            return -1;
        n--;
        return 0;
    }
    int Length(){return n;}
    int &operator[](int i)
    {
        if(i<0 || i>=n)
            throw 3;
        return s[i];
    }
};
