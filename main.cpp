#include "CStack.h"
#include "CStack2.h"

int main(void)
{
CStack2 r;
int w;
ofstream file("buffer.txt");
if(!file)
{
    cout<<"Error! Cannot open file..."<<endl;
    return -1;
}
file.close();
const char* f="buffer.txt";
cout<<"Hello there! You are welcome to stack builder!"<<endl;
cout<<"How much memory do you want to allocate?"<<endl;
cin>>w;
if(cin.fail() || w<=0)
         {
             cout<<"Error! Wrong number";
             exit(1);
         }
CStack c(w);
cout<<"Choose operation with stack:"<<endl;
vvod(c,r,f);
Autotest();
return 0;
}
