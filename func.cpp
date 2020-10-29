#include "CStack.h"
#include "CStack2.h"


int CStack :: Push(const string&x, CStack2 &h, const char* filename)
{
    int m=0;
    m=PushTop(x);
    if (m!=0)
    {
        ofstream file(filename, ios::app);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        for(int i=0; i<Length(); i++)
        {
            file<<s[i]<<endl;
        }

        file<<"-------------------------"<<endl;
        h.PushTop(Length());
        Clean();
        m=PushTop(x);
        file.close();
        return 1;
    }

    return 0;
}

int CStack ::  Del(CStack2 &r, const char* filename)
{
    int m=0;
    m=DelTop();

    if(m!=0)
    {
        string line;
        int j=0;
        ifstream file(filename),file2(filename);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        while (getline(file,line))
        {
            j++;
        }
        if(j==0)
        {
            cout<<"Stack is empty..."<<endl;
            return 2;
        }
        file.close();
        if(!file2)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        int u=0;
        string *str=new string[j];
        while (getline(file2,line))
        {
           str[u]=line;
           u++;
        }
        int N;
        N=r.GetTop();
        for (int d=j-N-1; d<j-2;d++)
        {
            PushTop(str[d]);
        }
        file2.close();
        ofstream file1(filename);
        if(!file1)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        for(int g=0; g<j-N-1; g++)
        {
            file1<<str[g]<<endl;
        }
        file1.close();

        delete[] str;
        str=NULL;
        r.DelTop();
        return 1;
    }

    return 0;

}

int  CStack :: Get(string&x, CStack2 &r, const char* filename )
{
    int m=0;
    m=GetTop(x);

    if(m!=0)
    {
        string line;
        int j=0;
        ifstream file(filename),file2(filename);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        while (getline(file,line))
        {
            j++;
        }
        if(j==0)
        {
            cout<<"Stack is empty..."<<endl;
            return 2;
        }
        file.close();
        if(!file2)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        int u=0;
        string *str=new string[j];
        while (getline(file2,line))
        {
           str[u]=line;
           u++;
        }
        int N;
        N=r.GetTop();
        for (int d=j-N-1; d<j-1;d++)
        {
            PushTop(str[d]);
        }
        file2.close();
        ofstream file1(filename);
        if(!file1)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        for(int g=0; g<j-N-1; g++)
        {
            file1<<str[g]<<endl;
        }
        file1.close();

        delete[] str;
        str=NULL;
        r.DelTop();
        m=GetTop(x);
        return 1;

    }

    return 0;

}

void vvod(CStack&c, CStack2 &r, const char* f)
{
string b;
int a=0;
while(a!=6)
{
  cout<<"1) Push;"<<endl;
  cout<<"2) Get;"<<endl;
  cout<<"3) Delete;"<<endl;
  cout<<"4) TopLength;"<<endl;
  cout<<"5) Length;"<<endl;
  cout<<"6) Stop;"<<endl;
  cin>>a;
  if(cin.fail())
         {
             cout<<"Error! Wrong number";
             exit(1);
         }
  if(a==1)
  {
      cout<<"Write down your string:"<<endl;
      cin>>b;
      int u=c.FullMemory();
      if(b.length()>u)
      {
          cout<<"Error! Too big number";
             exit(1);
      }
      c.Push(b,r,f);
  }
  if(a==2)
  {
      cout<<"The top string is:"<<endl;
      c.Get(b,r,f);
      cout<<b<<endl;
  }
  if(a==3)
  {
      cout<<"Deleting top string..."<<endl;
      c.Del(r,f);
  }
  if(a==4)
  {
      cout<<"Length of top string is:"<<endl;
      cout<<c.LenTop()<<endl;
  }
  if(a==5)
  {
      cout<<"Length of stack is:"<<endl;
      cout<<c.Length()<<endl;

  }
  cout<<"Current Stack is:"<<endl;
  c.print();
  cout<<"--------------------------------------"<<endl;

}
}
