#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;
#define TIME 100
#define HZ 3000

void asd(char* str)
{
	if(!str)
		return;
	cout<<str<<" ";
	for (int i=0; *(str+i)!=NULL; ++i)
	{
		if (*(str+i)=='.')
			Beep(HZ,TIME);
		if (*(str+i)=='_')
			Beep(HZ,TIME*6);
		if(*(str+i+1) != NULL)
			Sleep(TIME/2);
	}
}
char* Decoding(char* str, int i, char* l, bool& exit)
{
	char c = *(str+i);
	if(c>64 && c<91)
		c+=32;
	switch (c)
	{
	case ' ':
		Sleep(TIME*8);
		l = NULL;
		cout<<"  ";
		break;
	case'a':
		l="._";
		break;
	case'b':
		l="_...";
		break;
	case'c':
		l="_._.";
		break;
	case'd':
		l="_..";
		break;
	case'e':
		l=".";
		break;
	case'f':
		l=".._.";
		break;
	case'g':
		l="__.";
		break;
	case'h':
		l="....";
		break;
	case'i':
		l="..";
		break;
	case'j':
		l=".___";
		break;
	case'k':
		l="._.";
		break;
	case'l':
		l="._..";
		break;
	case'm':
		l="__";
		break;
	case'n':
		l="_.";
		break;
	case'o':
		l="___";
		break;
	case'p':
		l=".__.";
		break;
	case'q':
		l="__._";
		break;
	case'r':
		l="._.";
		break;
	case's':
		l="...";
		break;
	case't':
		l="_";
		break;
	case'u':
		l=".._";
		break;
	case'v':
		l="..._";
		break;
	case'w':
		l=".__";
		break;
	case'x':
		l="_._._.";
		break;
	case'y':
		l="__..__";
		break;
	case'z':
		l="..__..";
		break;
	case'0':
		l="_____";
		break;
	case'1':
		l="____.";
		break;
	case'2':
		l="___..";
		break;
	case'3':
		l="__...";
		break;
	case'4':
		l="_....";
		break;
	case'5':
		l=".....";
		break;
	case'6':
		l="...._";
		break;
	case'7':
		l="...__";
		break;
	case'8':
		l="..___";
		break;
	case'9':			
		l=".____";
		break;
	case '~':
		l = NULL;
		cout<<"Exit!";
		exit = 1;
		break;
	default:
		l="?";
	}
	return l;
}
void main()
{
	fstream history;
	char* str=new char [100];
	bool exit=0;

	history.open("History.txt" , ios::out | ios::app);
	if(!history)
		cout<<"The history didn't open.\n";

	while(!exit)
	{
		cout<<"Enter the word:"<<endl;
		cin.getline(str,100,'\n');
		history<<str;
		char * l=new char[5];
		for(int i=0; i<strlen(str); ++i)
		{
			l = Decoding(str,i,l,exit);
			if(exit)
				break;
			asd(l);
		}
		Sleep(TIME*8);
		system("cls");
	}

	history<<"\n";
	history.close();
}