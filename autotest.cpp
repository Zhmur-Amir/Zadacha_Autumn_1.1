#include "CStack.h"
#include "CStack2.h"


void Autotest(void)
{
   CStack c(100),b(100);
   CStack2 a;
   string x,t,q, y="abc101", k="hello",h="bye";
   bool s=true;
   const char* f="auto.txt";
   cout<<"==============================="<<endl<<"Autotest started..."<<endl;
   ofstream file("auto.txt");
   if(!file)
   {
        cout<<"Error! Cannot open file..."<<endl;
   }
   file.close();
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
   Push(y,b,a,f);
   Push(k,b,a,f);
   Push(h,b,a,f);
   Get(x,b,a,f);
   Del(b,a,f);
   Get(t,b,a,f);
   Del(b,a,f);
   Get(q,b,a,f);
   Del(b,a,f);
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
