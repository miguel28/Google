#include <iostream>
#include <stdio.h> 
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;
int T,N;
char line[50*100];
int O[200],B[200];
char sequence[200];
int numitemO=0, numitemB=0,seqnum=0;

int pasos;
bool Obut[200],Bbut[200];
int Opos,Bpos;

void in_format(void);
void SeqAlgoritm(void);

int main(void)
{
	system("clear");
	//cin >> T;
	T=20;
	
	ofstream myfile;
	myfile.open("output.txt");
		
	int i,z;
	for(i=0; i<T; i++){
		
		int c,j;
		j=0;
		while((c = getchar()) != '\n')
			line[j++] = c;
		line[j]=' ';
		line[j+1]='\0';
		
		cout << line << "Final"<<endl;
		
		seqnum=0;
		for(z=0; z<200; z++)sequence[z]=' ';
		
		in_format();
		for(z=0; z<seqnum; z++)cout << sequence[z];
			cout << seqnum<< endl;
		for(z=0; z<numitemO; z++)
			cout << O[z]<< " ";
		cout << numitemO<< endl;
		
		for(z=0; z<numitemB; z++)
			cout << B[z]<< " ";
		cout << numitemB << endl;
		
		
		SeqAlgoritm();
		myfile << "Case #" << i+1 << ": " << pasos << endl;
	}
	
	
	
	
	return 0;
}


void in_format(void)
{
	char temp[320];
	int c,q;
	
	int LineLen = strlen(line);
	int k,m,lastpos=0,x;
	numitemO=0; numitemB=0;
	int templen=0;
	int numspacios=0;
	int ultimaK;
	int help;
	for(k=0; k<32; k++) temp[k]='\0';
	
	N=0;

	for(k=0; k<LineLen; k++)
	{
		if(line[k]==' '&&N==0)
		{
			for(m=0; m<k; m++){
				temp[m]=line[m];
			}
			temp[k]=='\0';
			cout << "String: "<< temp << "."<<endl;
			sscanf(temp,"%d",&N);
			help=strlen(temp)+1;
			ultimaK=help;
			cout << "Help: "<< help <<endl;
			for(q=0; q<32; q++) temp[q]='\0';
			break;
		}
		
	}
	for(k=help; k<LineLen; k++)
	{

		if(line[k]==' '&&numspacios<2)
		{
			numspacios++;
		}
		if(numspacios==2)
		{
			//cout <<"ultimak: "<<ultimaK<<endl;
			for(m=ultimaK+2; m<=k; m++){
				temp[m-ultimaK-2]=line[m];
				//cout <<m<<" "<<line[m]<<endl;
				templen++;
			}
			temp[k-ultimaK]='\0';
			cout <<"TEmp: "<< temp<<endl;
			if(line[ultimaK]=='O')
			{
				sscanf(temp,"%d",&O[numitemO]);
				numitemO++;
				sequence[seqnum]='O';
			}

			if(line[ultimaK]=='B')
			{
				sscanf(temp,"%d",&B[numitemB]);
				numitemB++;
				sequence[seqnum]='B';
			}
			for(q=0; q<32; q++) temp[q]='\0';
			seqnum++;
			ultimaK=k+1; 
			templen=0;
			numspacios=0;
		}       
	}                               
}

void SeqAlgoritm(void)
{
	int z;
	for(z=0; z<200; z++){
		Obut[z]=false;
		Bbut[z]=false;
	}
	
	seqnum=0;
	pasos=0;
	Opos=1;
	Bpos=1;
	bool Salir;
	bool delay;
	int Ot=0,Bt=0;
	
	if(numitemO==0)
	{
		numitemO++;
		Obut[0]=true;
		Ot++;
	}
	if(numitemB==0)
	{
		numitemB++;
		Bbut[0]=true;
		Bt++;
	}

	while(!Salir)
	{
		
		cout << "Paso: " << pasos+1 <<"  : ";
		
		if(delay)
		{
			//cout << "Aumentar sec "<<endl;
			seqnum++;
			if(Ot>=numitemO&&Bt>=numitemB)Salir=true;
			delay=false;
		}
	if(!Salir){
		if(Ot<numitemO){	/////Orange Movements
			if(O[Ot]>Opos)///Orage se mueve hacia delante
			{
				Opos++;
				cout << "Orange: move to +"<<Opos<< " . ";
			}
			else if(O[Ot]<Opos)
			{
				Opos--;
				cout << "Orange: move to -"<<Opos<< " . ";
			}
			else if(O[Ot]==Opos){
				if(sequence[seqnum]=='O'){
					cout << "Orange: push button "<<Opos<< " . ";
					Obut[O[Ot]]=true;
					Ot++;
					delay=true;
				}
				else if(sequence[seqnum]=='B'){
					cout << "Orange: stay at button "<<Opos<<" " <<seqnum <<" . ";
				}
				else{
					cout <<"Orange: Break"<<endl;
					break;
				}
			}
		}
		else cout << "Orange: termino "<<Opos<< " . ";
		///// BLue Movements
		if(Bt<numitemB)
		{
			if(B[Bt]>Bpos)///Blue se mueve hacia delante
			{
				Bpos++;
				cout << "Blue: move to +"<<Bpos<< " " << B[Bt] <<endl;
			}
			else if(B[Bt]<Bpos)
			{
				Bpos--;
				cout << "Blue: move to -"<<Bpos << " " << B[Bt] <<endl;
			}
			else if(B[Bt]==Bpos){
				if(sequence[seqnum]=='B'){
					cout << "Blue: push button "<<Bpos<< endl;
					Bbut[B[Bt]]=true;
					Bt++;
					delay=true;
					
				}
				else if(sequence[seqnum]=='O'){
					cout << "Blue: stay at button "<<Bpos<< endl;
				}
				else{
					cout <<"Blue: Break"<<endl;
					break;
				}
			}
		}
		else cout << "Blue: termino "<<Bpos<< endl;
		pasos++;
	}

	}
	cout << "Pasos: "<< pasos << endl;
}
