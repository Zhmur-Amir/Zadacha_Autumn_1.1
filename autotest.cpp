#include "CStack.h"


void Autotest(void)
{
   CStack c,b;
   string x,t,q, y="abc101", k="hello",h="bye";
   bool s=true;
   const char* f="auto.txt";
   cout<<"==============================="<<endl<<"Autotest started..."<<endl;
   c.PushTop(y);
   if(c[0]!=y)
   {
       s=false;
   }
   c.GetTop(x);
   if(x!=y)
   {
       s=false;
   }
   c.DelTop();
   if(c.Length()!=0)
   {
       s=false;
   }
   Push(y,b,f);
   Push(k,b,f);
   Push(h,b,f);
   Get(x,b,f);
   Del(b,f);
   Get(t,b,f);
   Del(b,f);
   Get(q,b,f);
   Del(b,f);
   if( x==h && t==k && q==y)
   {
   }
   else
   {
       s=false;
   }

    if(s==true)
    {
        cout<<"Autotest passed! respect+"<<endl;
    }
    else
    {
        cout<<"Autotest failed! Wasted..."<<endl;
    }

}
