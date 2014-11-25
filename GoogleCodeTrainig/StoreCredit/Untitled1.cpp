#include <iostream>
using namespace std;
int main(void)
{
    char intp[2000*10];
     int ca,x=0;
     
     do
     {
         ca=getchar();
         intp[x++]=(char)ca;
     }
     while(ca != '\n');
     
     intp[x]='\0';
     
     
     int LineLen = strlen(intp);
     int k,m,lastpos=0,numitem=0;
        
     cout << "Len: " <<LineLen <<endl<< intp <<endl;
return 0;    
}
