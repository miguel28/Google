#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;
int T,K,N;
char norotbuffer[50][50];
char mirrorbuffer[50][50];
char buffer[50][50];
bool Rwins,Bwins;
char finaltext[20*100];
int finalpos=0;

char Labels[4][10]={"Neither","Red","Blue","Both"};

void Rotate();
void Gravity();
void Compare();

int main(void){
	system("clear");
	cin>>T;
	
	int i,j;
	int x,y;
	int c,f;
	ofstream myfile;
	myfile.open("A-large.out");
	
	for(i=0; i<T; i++)
	{
		cout <<"Case #"<<i+1+88<<endl;
		scanf("%d %d",&N,&K);
		for(j=0;j<N; j++)
			/*f=0;
			while((c = getchar()) != '\n')
			norotbuffer[j][f++] = c;
			norotbuffer[j][f]='\0';*/
			cin>>norotbuffer[j];

		Rotate();
		/*for(x=0; x<N; x++)
		{
			for(y=0; y<N; y++)
				cout<<buffer[x][y];
			cout << endl;
		}*/
		cout << endl;//*/
		Gravity();
		for(x=0; x<N; x++)
		{
			for(y=0; y<N; y++)
				cout<<buffer[x][y];
			cout << endl;
		}
		cout << endl;//*/
		Compare();
		/*for(x=0; x<N; x++)
		{
			for(y=0; y<N; y++)
				cout<<buffer[x][y];
			cout << endl;
		}//*/
		//cout << endl;
		
		/*char tempchar[32];
		int q;
		sprintf(tempchar,"%s%d%s%s","Case #",i+1,": ",Labels[Rwins+(Bwins*2)]);
		for(q=0; q<strlen(tempchar); q++)
		{
			finaltext[finalpos+q]=tempchar[q];
		}
		finaltext[strlen(tempchar)+finalpos]='\n';
		finalpos+=strlen(tempchar)+1;
		
		*/
		myfile << "Case #" << i+1 << ": " << Labels[Rwins+(Bwins*2)] << endl;
		
	}
	/*finaltext[finalpos+1]='\0';
	cout << finaltext;
	myfile << finaltext;*/
	return 0;	
}

void Rotate()
{
	int b,n,m;
	for(b=0;b<N; b++)
	{
		for(n=0;n<N; n++)
		{
			mirrorbuffer[n][b]=norotbuffer[b][n];
		}
	}
	for(b=0;b<N; b++)
	{
		for(n=0;n<N; n++)
		{
			buffer[b][N-n-1]=mirrorbuffer[b][n];
		}
	}
}

void Gravity()
{
	int b,n,m;
	for(b=N-1;b>=0; b--)
	{
		for(n=0;n<N; n++)
		{
			if(buffer[b][n]=='.')
			{
				//cout << "Encontro Espacio" << endl;
				for(m=b-1; m>=0; m--) {
					if(buffer[m][n]!='.')
					 {
						 //cout << buffer[m][n] << " " << buffer[b][n]<< endl;
						 buffer[b][n]=buffer[m][n];
						 buffer[m][n]='.';
						 break;
					 }
				}
			}
		}
	}
}

void Compare()
{
	int b,n,m,u;
	int matches=0;
	Rwins=false;
	Bwins=false;
	
	////Horizontal Line
	 //Red
	
	for(b=0;b<N; b++)
	{
		if(matches<K)
		{
			matches=0;
			for(n=0;n<N; n++)
			{
				//cout << "Line: " << b << "Row: " << n << endl;
				if(matches<K)
				if(buffer[b][n]=='R')
				{
					matches++;
				}
				else matches=0;
			
			}
			//cout << "MatchesR: " << matches << endl;
		}
	}
	if(matches>=K)Rwins=true;

    //Blue
	matches=0;
	for(b=0;b<N; b++)
	{
		if(matches<K)
		{
			matches=0;
			for(n=0;n<N; n++)
			{
				if(matches<K)
				if(buffer[b][n]=='B')
				{
					matches++;
					//cout << "MB";
				}
				else matches=0;
			}
			//cout << "MatchesB: " << matches << endl;
		}
	}
	if(matches>=K)Bwins=true;

	////Vertical Line
	//Red
if(!Rwins){
	matches=0;
	for(b=0;b<N; b++)
	{
		if(matches<K)
		{
			matches=0;
			for(n=0;n<N; n++)
			{
				if(matches<K)
				if(buffer[n][b]=='R')
				{
					matches++;
				}
				else matches=0;
				
			}
			//cout << "MatchesR: " << matches << endl;
		}
	}
	if(matches>=K)Rwins=true;
}
	
    //Blue
if(!Bwins){
	matches=0;
	for(b=0;b<N; b++)
	{
		
		if(matches<K)
		{
			matches=0;
			for(n=0;n<N; n++)
			{
				if(matches<K)
				if(buffer[n][b]=='B')
				{
					matches++;
				}
				else matches=0;
			}
		}
	}
	if(matches>=K)Bwins=true;
}//*/
	

	//////Diagonal Invertida
		///Red
if(!Rwins){
	matches=0;
	for(b=0;b<N; b++)
	{
		for(n=0; n<N; n++)
		{
			if(matches<K){
				matches=0;
				for(m=0;m<N; m++)
				{
				
					if(matches<K)
					{
						if(m+b<N&&m+n<N)
						{
							if(buffer[b+m][n+m]=='R')
							{
								matches++;
							}
							else matches=0;
							//cout << matches << " " << buffer[b+m][n+m] << " " <<  m+b << " " << m+n << endl;
						}
					}
				}
			}
		}
	}
	
	if(matches>=K)Rwins=true;
}
	
		///Blue
if(!Bwins){
	matches=0;
	for(b=0;b<N; b++)
	{
		for(n=0; n<N; n++)
		{
			if(matches<K){
				matches=0;
				for(m=0;m<N; m++)
				{
					
					if(matches<K)
					{
						if(m+b<N&&m+n<N)
						{
							if(buffer[b+m][n+m]=='B')
							{
								matches++;
							}
							else matches=0;
							//cout << matches << " " << buffer[b+m][n+m] << " " <<  m+b << " " << m+n << endl;
						}
					}
				}
			}
		}
	}
	
	if(matches>=K)Bwins=true;	
}//*/

	/////Diagonal
if(!Rwins){	
	matches=0;
	for(b=0;b<N; b++)
	{
		for(n=0; n<N; n++)
		{
			if(matches<K){
				matches=0;
				for(m=0;m<N; m++)
				{
					
					if(matches<K)
					{
						if(m+b<N&&(N-(n+m))>=0)
						{
							if(buffer[b+m][N-(n+m)]=='R')
							{
								matches++;
							}
							else matches=0;
							//cout << matches << " " << buffer[b+m][n-m] << " " <<  m+b << " " << N-(n+m) << endl;
						}
					}
				}
			}
		}
	}
	
	if(matches>=K)Rwins=true;
}
	////Blue
if(!Bwins){		
	matches=0;
	for(b=0;b<N; b++)
	{
		for(n=0; n<N; n++)
		{
			if(matches<K){
				matches=0;
				for(m=0;m<N; m++)
				{
					
					if(matches<K)
					{
						if(m+b<N&&(N-(n+m))>=0)
						{
							if(buffer[b+m][N-(n+m)]=='B')
							{
								matches++;
							}
							else matches=0;
							cout << matches << " " << buffer[b+m][n-m] << " " <<  m+b << " " << N-(n+m) << endl;
						}
					}
				}
			}
		}
	}
	if(matches>=K)Bwins=true;
}
	//*/
	cout << Rwins << " " << Bwins << endl;
}