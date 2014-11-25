#include <iostream>
#include <stdio.h> 
#include <string.h>

using namespace std;

typedef struct
{
	int len;
	char text[256];
}typetext;
int n;

void InvertString(char *text);
void InvertLineWords(char *text);

int main(void)
{
	cin>>n;
	cout<< "1";
	typetext l[n];
	int i,j;

	cout<< "2";
	for(i=0; i<n; i++)
	{
		int c;
		while((c = getchar()) != '\n')
		l[i].text[j++] = c;
		l[i].text[j]='\0';
	}
	for(i=0; i<n; i++)
	{
		InvertLineWords(l[i].text);
	}


	return 0;
}


void InvertLineWords(char text[1024])
{
	
	
	int PosLine;
	int LenLine = strlen(text);
	int NumSpaces=0;
	int i;
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
		for(i=0; i<LenLine-1; i++)
		{
			finaltext[i]=text[i];
			
		}
	}
	
	cout << finaltext<< endl;
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

