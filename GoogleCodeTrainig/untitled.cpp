#include <iostream.h>
int N;
int i;
typedef struct
{
	char text[25];
}texttype;



int main(void){
	
	cin>>N;
	texttype L[N];
	for(i=0; i<=N;i++)
	{
		cin>>L[i].text;		
	}
	
	
	
	return 0;	
}

char* reverse_words(char* text)
{
	int num_words=0;
	texttype word[25];
	int f=0;
	while(text[f]!=' ')
	{
		word[num_words].text[f]=text[f];
		f++;
	}	
	
	
}