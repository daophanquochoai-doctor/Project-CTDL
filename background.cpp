#include<iostream>
#include<fstream>
#include "background.h"
//#include "ReadFile.h"


using namespace std;

void Insert_pass( string &pass, int &x, int &y )
{
	char kitu;
	gotoxy(x,y);
	ShowConsoleCursor(1);
	while (true) {
        kitu = getch();
        if( kitu == '\r' ) break;
        ShowConsoleCursor(0);
        if( kitu == BACKSPACE )
		{
			if( x == 94 )
			{
				ShowConsoleCursor(1);
				continue;
			}
				gotoxy(--x,y);
				cout << " ";
				pass.erase(pass.length()-1,1);
		}
		else if( kitu == ESC )	return;
		else if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!' )
        {
        	pass += kitu;
        	gotoxy(x++,y);
        	cout << '*';
		}
    }
    color_rectangle(96,27,20,3,Light_Green);
	insert_title(96,27,Bright_White,20,4,"LOGIN");
}

void Insert_user( string &user,string &pass, int &x, int &y,int &v,int &t )
{
	gotoxy(x,y);
	char kitu;
	ShowConsoleCursor(1);
	while( true )
	{
		kitu = getch();
		if( kitu == '\r' ) break;
		ShowConsoleCursor(0);
		if( kitu == BACKSPACE )
		{
			if( x == 94 )
			{
				ShowConsoleCursor(1);
				continue;
			}
				gotoxy(--x,y);
				cout << " ";
				user.erase(user.length()-1,1);
		}
		else if( kitu == ESC )	return;
		else if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!' )
        {
        	user += kitu;
        	gotoxy(x++,y);
        	cout << kitu;
		}
	}
	Insert_pass(pass,v,t);
}

void Insert_Loggin( string &user, string &pass,int &x,int &y,int &v,int &t)
{
	Insert_user(user,pass,x,y,v,t);
}

void menu()
{
	show_rectangle(1,1,130,32,Purple);
	show_tittle(22,4);
	show_rectangle(85,10,40,16,Purple);
	
}

//note
void Note_Acc( int x, int y, int width, int height, string note, int color,int &end)
{
	show_rectangle(x,y,width,height,color);
	color_rectangle(x+1,y+1,width,height-1,color);
	insert_title(x,y,color,width,height+1,note);
	int key;
	key = getch();
	switch(key)
	{
		case ENTER: break;
		case ESC: end=0;
					break;
	}
}

//load 
void Load( string user, string pass, int &end)
{
	int x = 94, y = 19;
	int v = 94, t = 24;
	Insert_Loggin(user,pass,x,y,v,t);
	int catkey;
	while( catkey != ENTER )
	{
		catkey = getch();
		switch( catkey )
		{
			case ENTER:
			{
						if( Check_Account(user,pass,fileaccount) )
						{
							system("cls");
							end = 0;
							menu();
						}
						else Note_Acc(40,16,40,4,"TAI KHOAN KHONG TON TAI!",Red,end);
						break;
					break;
			}
			case ESC : break;
			case UP:
				{
					color_rectangle(96,27,20,3,Purple);
					insert_title(96,27,Aqua,20,4,"LOGIN");
					Insert_pass(pass,v,t);
					break;
				}
			case DOWN:
				{
					color_rectangle(96,27,20,3,Purple);
					insert_title(96,27,Aqua,20,4,"LOGIN");
					Insert_user(user,pass,x,y,v,t);
					break;
				}
		}
	}
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
	getch();
	return 0;
}
