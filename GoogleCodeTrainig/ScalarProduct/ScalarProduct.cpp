#include <iostream>
#include <stdio.h> 
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

int n,T;
char v1str[1000*100],v2str[1000*100];
int v1[800],v2[800];
int total;
long ftotal;

void in_format(void);
void ScalarProduct(int cases);
void process(int* P, int N, int* total);
void swap(int *x, int *y);
int B(int N, int c);
void lexperms (int *P, int *O, int N, int *total);
void perms1 (int *P, int N, int *total);
void perms2 (int *P, int N, int *total);

int main(void)
{
	system("clear");
	cin>>T;

   ofstream myfile;
	myfile.open("output.txt");

	int c;
	
	int i,j;

	for(i=0; i<T; i++)
	{
		cin>>n;	

		j=0;//// pa ke jale
		while((c = getchar()) != '\n')
		v1str[j++] = c;
		v1str[j]= ' ';
		v1str[j+1]='\0';///// Pa ke jale

		j=0;
		while((c = getchar()) != '\n')
		v1str[j++] = c;
		v1str[j]= ' ';
		v1[j+1]='\0';


		j=0;
		while((c = getchar()) != '\n')
		v2str[j++] = c;
		v2str[j]= ' ';
		v2str[j+1]='\0';
		in_format();
		ftotal=2147483647;
		perms1(v1,n, &total);
		
		//ScalarProduct(n);
		cout << "Case #" << i+1 << ": " << ftotal << endl;
		myfile << "Case #" << i+1 << ": " << ftotal << endl;
	}
	
	
	/*
	cout << "Prueba String:" << v1str << ":" << v2str << endl;

	cout << "Prueba Nums: "<<endl;
	for(i=1; i<=n; i++)
		cout << v1[i] << " ";
   cout << endl;
 	for(i=1; i<=n; i++)
		cout << v2[i] << " ";
   cout << endl;//*/



	return 0;
}


void in_format(void)
{
   
	  char temp[32];

     int v1Len = strlen(v1str);
     int k,m,lastpos=0,numitem=1,templen=0;
        
     //cout << "Len: " << v1Len <<endl;
     for(k=0; k<32; k++) temp[k]='\0';
     for(k=0; k<v1Len; k++)
     {
       if(v1str[k]==' ')
       {
		   //cout << lastpos<< " " << k<<endl;
		   for(m=lastpos; m<k; m++){
             temp[m-lastpos]=v1str[m];
			 templen++;
		   }
		   for(m=templen; m<32; m++)temp[m]='\0';
		   temp[k]='\0';
         //cout << "Temp: " <<temp << "  " << strlen(temp) << endl;
         
		   sscanf(temp,"%d",&v1[numitem]);
         numitem++;
         lastpos=k+1; 
		 templen=0;
       }       
     } 
	  
     char temp2[32];
	  int v2Len=strlen(v2str);
	  int numitemv2=1; int lastposv2=0; int templenv2=0;
     k=0;

	  //cout<< "String: " << v2str << "Len: " << v2Len <<endl;
 
	  for(k=0; k<32; k++) temp2[k]='\0';
     for(k=0; k<v2Len; k++)
     {
       if(v2str[k]==' ')
       {
		   //cout << lastposv2<< " " << k<<endl;
		   for(m=lastposv2; m<k; m++){
             temp2[m-lastposv2]=v2str[m];
			 templenv2++;
		   }
		   for(m=templenv2; m<32; m++)temp2[m]='\0';
		   temp2[k]='\0';
         //cout << "Temp: " <<temp2 << "  " << strlen(temp2) << endl;
         
		   sscanf(temp2,"%d",&v2[numitemv2]);
         numitemv2++;
         lastposv2=k+1; 
		 templenv2=0;
       }       
     }                        
}

void ScalarProduct(int cases)
{
	int y;	
	int temptoltal=0;
//cout<< "Final" << endl;
	for(y=1; y<=cases; y++){
		temptoltal+= v1[y]*v2[y];
		//cout << v1[y]<< " " << v2[y] << " " << v1[y]*v2[y]  << " " << temptoltal << endl;
	}
	if(temptoltal<=ftotal)
		ftotal=temptoltal;
	
//cout<< total << endl;
}



void process(int* P, int N, int* total) { 
	int i; /*printf("* \n"); 
	for (i=N; i>0; i--) {
		printf("%d ", P[i]);
	}  
	printf("\n");//*/
	
	perms2(v2,n,total);
	
	ScalarProduct(n);
	(*total) ++;
}

void process2(int* P, int N, int* total) { 
	/*int i;  
	for (i=N; i>0; i--) {
		printf("%d ", P[i]);
	}  
	printf("\n");//*/
	
	//ScalarProduct(n);

}

void swap(int *x, int *y) { 
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverse (int *P, int N) {
	int i = 1;  
	while ( i < (N+1-i) ) {
		swap(&P[i], &P[N+1-i]);
		i ++;
	}
}

int B(int N, int c) {  
	return ( (N % 2) != 0 ? 1 : c );
}

void lexperms (int *P, int *O, int N, int *total) {
	
	int i,j;
	int c[N];
	int d[N];
	for (i = N; i > 1; i --) {
		c[i] = 1;
	}
	i = 2;
	
	for (j = N; j > 1; j --) {
		d[j] = 1;
	}
	j = 2;
	
	process(P,N,total);
	process(O,N,total); 
	do {
		if (c[i] < i) {
			swap(&P[i],&P[c[i]]);
			reverse(P,i-1); /* inversion parcial! */
			process(P,N,total);
			c[i] ++;
			i = 2;
		} else {
			c[i] = 1;
			i ++;
		}/////
		if (d[j] < j) {
			swap(&O[j],&O[d[j]]);
			reverse(O,j-1); /* inversion parcial! */
			process(O,N,total);
			d[j] ++;
			j = 2;
		} else {
			d[j] = 1;
			j ++;
		}
	} while (i <= N&&j<=N);
}

void perms1 (int *P, int N, int *total) {
	
	int i;
	int c[N];

	for (i = N; i > 1; i --) {
		c[i] = 1;
	}
	i = 2;
	

	
	process(P,N,total);
	do {
		if (c[i] < i) {
			swap(&P[i],&P[c[i]]);
			reverse(P,i-1); /* inversion parcial! */
			process(P,N,total);
			c[i] ++;
			i = 2;
		} else {
			c[i] = 1;
			i ++;
		}
	} while (i <= N);
}

void perms2 (int *P, int N, int *total) {
	
	int i;
	int c[N];
	
	for (i = N; i > 1; i --) {
		c[i] = 1;
	}
	i = 2;
	
	
	
	process2(P,N,total);
	do {
		if (c[i] < i) {
			swap(&P[i],&P[c[i]]);
			reverse(P,i-1); /* inversion parcial! */
			process2(P,N,total);
			c[i] ++;
			i = 2;
		} else {
			c[i] = 1;
			i ++;
		}
	} while (i <= N);
}