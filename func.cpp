#include "CStack.h"

int Push(const string&x, CStack &c, const char* filename)
{
    int m=0;
    m=c.PushTop(x);
    if (m!=0)
    {
        ofstream file(filename, ios::app);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        for(int i=0; i<N; i++)
        {
            file<<c[i]<<endl;
        }

        file<<"-------------------------"<<endl;
        c.Clean();
        m=c.PushTop(x);
        file.close();
        return 1;
    }

    return 0;
}

int Del(CStack &c, const char* filename)
{
    int m=0;
    m=c.DelTop();

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
        for (int d=j-N-1; d<j-2;d++)
        {
            c.PushTop(str[d]);
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
        return 1;
    }

    return 0;

}

int Get(string&x, CStack &c,const char* filename )
{
    int m=0;
    m=c.GetTop(x);

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
        for (int d=j-N-1; d<j-1;d++)
        {
            c.PushTop(str[d]);
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

        m=c.GetTop(x);
        return 1;

    }

    return 0;

}

void vvod(CStack&c, const char* f)
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
      Push(b,c,f);
  }
  if(a==2)
  {
      cout<<"The top string is:"<<endl;
      Get(b,c,f);
      cout<<b<<endl;
  }
  if(a==3)
  {
      cout<<"Deleting top string..."<<endl;
      Del(c,f);
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
