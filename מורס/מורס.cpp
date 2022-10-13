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
char* Decoding(char* str, int i, char* l/*, bool& exit*/)
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
	default:
		l="?";
	}
	return l;
}
bool functions(fstream& history, char* str, bool& exit)
{
	history.open("History.txt" , ios::out | ios::app);
	if(str[0] == '\\' && str[1] == 'c' && str[2] == 'l' && str[3] == 'e' && str[4] == 'a' && str[5] == 'r' && str[6] == ' ' && str[7] == 'h' && str[8] == 'i' && str[9] == 's' && str[10] == 't' && str[11] == 'o' && str[12] == 'r' && str[13] == 'y')//clear history
	{
		history.close();
		history.open("History.txt" ,  ios::out | ios::trunc);
		cout<<"history cleared!\n";
		system("pause");
		system("CLS");	
		history.close();
		return true;
	}
	else if(str[0] == '\\' && str[1] == 'e' && str[2] == 'x' && str[3] == 'i' && str[4] == 't')//exit
	{
		exit = 1;
		system("pause");
		system("CLS");
		history.close();
		return true;
	}
	else if(str[0] == '\\' && str[1] == 'h' && str[2] == 'e' && str[3] == 'l' && str[4] == 'p')//help
	{
		cout<<"\t"<<(char)175<<" clear history"<<endl
			<<"\t"<<(char)175<<" exit"<<endl
			<<"\t"<<(char)175<<" help"<<endl;
		system("pause");
		system("CLS");
		history.close();
		return true;
	}
	history.close();
	return false;
}
void main()
{
	fstream history;
	char* str=new char [100];
	bool exit=0;

	history.open("History.txt" , ios::out | ios::app);
	if(!history)
		cout<<"The history didn't open.\n";

	start_while:
	while(!exit)
	{
		cout<<"Enter the word:"<<endl;
		cin.getline(str,100,'\n');

		history.close();
		if(functions(history, str, exit))
		{
			history.open("History.txt" , ios::out | ios::app);
			goto start_while;
		}
		history.open("History.txt" , ios::out | ios::app);

		history<<str;
		history<<" ";
		char * l=new char[5];
		for(int i=0; i<strlen(str); ++i)
		{
			l = Decoding(str,i,l);
			if(l)
				history<<l<<" ";
			if(str[i] == ' ')
				history<<", ";
			if(exit)
				break;
			asd(l);
		}
		history<<"\n";
		Sleep(TIME*8);
		system("cls");
	}

	history<<"---exit---\n\n";
	history.close();
}