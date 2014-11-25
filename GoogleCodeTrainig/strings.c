#include <iostream>
#include <string.h>

using namespace std;


int main(void)
{
	string texto="hola todos";
	
	reversechar(texto);


	return 0;
}



void reversechar(char *text)
{
	int Long= Len(text);
	int i;
	char *finaltext;
	int j;
	for(i=Long; i>=0; i--)
	{
		
		strcat(finaltext[j],text[i]);
		j++;
	}


	//printf("%s",finaltext);
}

int Len(char *str)
{

	int x=0;
	while(str[x]!='\0')
		x++;

	return x;


}


