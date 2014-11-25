#include <iostream>
#include <stdio.h> 
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int n;

char finallines[100000];
int finalpos=0;

void InvertString(char *text);
void InvertLineWords(char text[256]);
int line=0;

int main(void)
{
	system("clear");
	cin>>n;


	int c;
	char l[1000];
	int i,j;

	for(i=0; i<=n; i++)
	{
		j=0;
		while((c = getchar()) != '\n')
		l[j++] = c;
		l[j]='\0';
		InvertLineWords(l);
		line++;
	}

	cout <<finallines<< endl;
	ofstream myfile;
	myfile.open("B-large-practice.out");
	myfile<<finallines<< endl;

	return 0;
}


void InvertLineWords(char text[256])
{
	
	//cout << "Cadena " << text << endl;
	int PosLine;
	int LenLine = strlen(text);
	int NumSpaces=0;
	int i;
	if(LenLine>0){
		for(i=0; i<LenLine; i++)
		{
			if(text[i]==' ')
				NumSpaces++;
		}
		//cout << "Longitud Cadena: "<< LenLine << endl;
		//cout << "Numero de Espacios: "<< NumSpaces << endl;
	
		int SpacePos[NumSpaces];
		int SpaceCounter=0;
		for(i=0; i<LenLine-1; i++)
		{
			if(text[i]==' ')
			{
				SpacePos[SpaceCounter]=i;
				SpaceCounter++;
			}
		
		}
		SpacePos[NumSpaces]=LenLine-1;
	
		//cout << "Posicion de cada espacio: " << endl;
		//for(i=0; i<=SpaceCounter; i++)cout << i << " : " << SpacePos[i] << endl;
	
		char finaltext[LenLine];
		int j;
	
		int FinalPos=0;
	
		//cout << "Longitud de Cada palabra " << endl;
	
		if(NumSpaces>0){	
		for(i=NumSpaces; i>=0; i--)
		{
		
			//cout << i << " : " << SpacePos[i]-SpacePos[i-1]-1 << endl;
			if(i==0){
				finaltext[FinalPos]=' ';
				FinalPos++;
			
			}
		
			if(i==NumSpaces)
			{
				for(j=SpacePos[NumSpaces-1]; j<LenLine-1; j++)
				{
					finaltext[FinalPos]=text[j+1];
					FinalPos++;
				}
			
			}
			else if(i==0)
			{
				for(j=0; j<SpacePos[0]; j++)
				{
					finaltext[FinalPos]=text[j];
					FinalPos++;
				}
			
			}
			else{
		
		
				for(j=SpacePos[i-1]; j<SpacePos[i]; j++)
				{
					finaltext[FinalPos]=text[j];
					FinalPos++;
				}	//
			}
		}
		}
		else
		{
			for(i=0; i<LenLine; i++)
			{
				finaltext[i]=text[i];
			
			}
		}
		finaltext[LenLine]='\0';
		char stringtemp[15];
		sprintf(stringtemp,"%s%d%s  %s","Case #",line+1,":","  ");
		if(line>98)
		{
			for(i=0; i<=11; i++)
			{
				finallines[i+finalpos]=stringtemp[i];	
			}
			finalpos+=11;
		}	
		else if(line<9)
		{
			for(i=0; i<=9; i++)
			{
				finallines[i+finalpos]=stringtemp[i];	
			}
			finalpos+=9;
		}
		else
		{
			for(i=0; i<=10; i++)
			{
				finallines[i+finalpos]=stringtemp[i];	
			}
			finalpos+=10;
		}

		for(i=0; i<LenLine; i++)
		{
			finallines[i+finalpos]=finaltext[i];	
		}
	
		finallines[LenLine+finalpos]='\n';
		finalpos+=i+1;//*/

	}else line--;
}


void InvertString(char *text)
{
	int len= strlen(text)-1;
	int i;
	char finaltext[256];

	for(i=0; i<len+1; i++)
	{
		finaltext[len-i]=text[i];

	}
	finaltext[len+1]='\0';
	cout << finaltext<<endl;

}

