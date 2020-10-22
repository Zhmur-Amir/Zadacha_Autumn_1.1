#include "CStack.h"

int main(void)
{
CStack c;
ofstream file("buffer.txt");
if(!file)
{
    cout<<"Error! Cannot open file..."<<endl;
    return -1;
}
file.close();
const char* f="buffer.txt";
cout<<"Hello there! You are welcome to stack builder!"<<endl;
cout<<"Choose operation with stack:"<<endl;
vvod(c,f);
Autotest();
return 0;
}
