#include<iostream>
#include<fstream>
#include "background.h"
//#include "ReadFile.h"


using namespace std;


void control()
{
	char catkey;
	int number = 1;
	catkey = getch();
	switch(catkey)
	{
		case UP:
			{
				if( number == 1 )
				{
					number = 3;
					show_rectangle(45,12,40,4,Purple);
					color_rectangle(46,13,40,3,Black);
					insert_title(45,12,Aqua,Black,40,5,"Lam Bai Thi");
					show_rectangle(45,22,40,4,Purple);
					color_rectangle(46,22,40,3,White);
					insert_title(45,22,Red,White,40,5,"THOAT");
				}
				else
				{
					number --;
				}
				break;
			}
		case ENTER:
			{
				if( number == 3 )
				{
					return;
				}
			}
	}
}

void Display_Info_SV()
{
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(2,2,128,5,Purple);
}


void sig_in()
{
	int end = 1;
	while( end != 0 )
	{
		string user, pass;
		console_loggin();
		Load(user,pass,end);
	}
}

int main()
{
	sig_in();
	return 0;
}

