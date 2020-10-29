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
   b.Push(y,a,f);
   b.Push(k,a,f);
   b.Push(h,a,f);
   b.Get(x,a,f);
   b.Del(a,f);
   b.Get(t,a,f);
   b.Del(a,f);
   b.Get(q,a,f);
   b.Del(a,f);
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
