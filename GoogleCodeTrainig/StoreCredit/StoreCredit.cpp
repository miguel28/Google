#include <iostream>
#include <stdio.h> 
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int P[2000];
int n,I,C,j,i;
int d1,d2;
//char intp[2000*100];
char finaloutput[25*5000];
int finalpos;

void in_format(void);
void compare(int cases);


int main(void)
{
    system("clear");
	cin>>n;
	ofstream myfile;

    myfile.open("A-Large.out");
	
    for(j=0; j<n; j++){
       cin>>C;
       cin>>I; 
       //cout << "Caso " << j << endl;
       in_format();
       compare(I); 
       char tempoutput[25];
       sprintf(tempoutput,"%s%d%s%d%s%d","Case #",j+1,": ", d1+1," ",d2+1);

		
       int templong = strlen(tempoutput);
    
       int o;
       for(o=0; o<templong; o++)
          finaloutput[o+finalpos]=tempoutput[o];         
       finaloutput[o+finalpos]='\n';
       finalpos+=templong+1;
    }
    finaloutput[finalpos]='\0';
	
    cout << finaloutput<<endl;
	myfile << finaloutput;
    
    
    /*for(i=0; i<I; i++)
    {
       cout << P[i]<<endl;          
             
    }
    cout << d1+1 << " " << d2+1 << endl;
    //*/
    
    
    
    return 0;   
}

void in_format(void)
{
     char temp[32];
     char intp[1000*100];
     int c,x;
	
	/*j=0;
	c = getchar();
	while((c = getchar()) != '\n')
		intp[j++] = c;
	intp[j]='\0';*/
	 /*    c=getchar();
     do
     {
		 c=getchar();
         intp[x++]=(char)c;
     }
     while(c != '\n');   
     intp[x]=' ';
     intp[x+1]='\0';//*/
	string s;
	getline(cin,s);
	strcpy(intp,s.c_str());
     int LineLen = strlen(intp);
     int k,m,lastpos=0,numitem=0,templen=0;
        
     //cout << "Len: " << LineLen <<endl<< intp <<endl;
     for(k=0; k<32; k++) temp[k]='\0';
     for(k=0; k<LineLen; k++)
     {
       if(intp[k]==' ')
       {
		   //cout << lastpos<< " " << k<<endl;
		   for(m=lastpos; m<k; m++){
             temp[m-lastpos]=intp[m];
			 templen++;
		   }
		   for(m=templen; m<32; m++)temp[m]='\0';
		   temp[k]='\0';
         //cout << "Temp: " <<temp << "  " << strlen(temp) << endl;
         
		 sscanf(temp,"%d",&P[numitem]);
         numitem++;
         lastpos=k+1; 
		 templen=0;
       }       
     }                               
}

void compare(int cases)
{
     int e,w; bool termino=false;
     for(e=0;e<cases; e++){
         for(w=0;w<cases; w++){
            //cout<<e <<"+"<<w<<"="<<P[e]+P[w]<<endl;
            if(e!=w){
               if(P[e]+P[w]==C&&!termino){
                  d1=e;
                  d2=w;       
                  termino=true;
               } 
            }                               
         }                                     
     }        
}
