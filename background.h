#include<iostream>
#include<string.h>
#include "ReadFile.h"
#include "mylib.h"

using namespace std;

string fileaccount = "Account.txt";

//ke khung rong
void show_rectangle( int x, int y, int width, int height, int color )
{
	SetColor(color);
	gotoxy(x,y);
	cout << char(201);
	gotoxy(x, y+height);
	cout << char(200);
	gotoxy(x+width, y+height);
	cout << char(188);
	gotoxy(x+width, y);
	cout << char(187);
	for( int i = 1 ; i < width ; i++ )
	{
		gotoxy(x+i, y);
		cout << char(205);
	}
	for( int i = 1 ; i < width ; i++ )
	{
		gotoxy(x+i, y+ height);
		cout << char(205);
	}
	for( int i = 1 ; i < height ; i++ )
	{
		gotoxy(x, y + i);
		cout << char(186);
	}
	for( int i = 1 ; i < height ; i++ )
	{
		gotoxy(x + width, y + i);
		cout << char(186);
	}
	SetColor(White);
}

//ke khung khong rong
void color_rectangle(int x, int y, int width, int height, int color)
{
	SetBGColor(color);
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width - 1; j++)
		{
			gotoxy(x + j, y + i); cout << " ";
		}
		gotoxy(x + 1, y + i) ; cout << " ";
	}
	SetBGColor(Black);
}

// in tittle
void show_tittle( int x, int y)
{
	gotoxy(x,y);
	cout << " _______ __     __   _______                    _______         __     __                   \n";
	gotoxy(x,y+1);
	cout << "|_     _|  |--.|__| |_     _|.----.---.-.----.  |    |  |.-----.|  |--.|__|.-----.--------. \n";
	gotoxy(x,y+2);
	cout << "  |   | |     ||  |   |   |  |   _|  _  |  __|  |       ||  _  ||     ||  ||  -__|        | \n";
	gotoxy(x,y+3);
	cout << "  |___| |__|__||__|   |___|  |__| |___._|____|  |__|____||___  ||__|__||__||_____|__|__|__| \n";
	gotoxy(x,y+4);
	cout << "                                                        |_____|							 \n";
}

//them tu vao dia chi
void insert_title(int x,int y,int color,int bgcolor, int width, int hight, string title)
{
	SetColor(color);
	SetBGColor(bgcolor);
	gotoxy(x + (width- title.length())/2 ,y + (hight - 1)/2);
	cout << title;
	SetColor(White);
	SetBGColor(Black);
}

//ve khung login
void console_loggin()
{
	resizeConsole(1100, 630);
	system("cls");
	show_tittle(22,4);
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(85,13,40,17, Purple);
	color_rectangle(86,14,40,3,Purple);
	insert_title(86,14,Aqua,Black,40,4," DANG NHAP ");
	show_rectangle(86,17,38,4,Purple);
	show_rectangle(86,22,38,4,Purple);
	SetColor(Blue);
	gotoxy(88, 19);
	cout << "User:";
	gotoxy(88, 24);
	cout << "Pass:";
	color_rectangle(96,27,20,3,Purple);
	insert_title(96,27,Aqua,Black,20,4,"LOGIN");
	SetColor(Green);
	gotoxy(85,31);
	cout << "*Vui long khong nhap ki tu sau: | \ ~ !";
	SetColor(White);
}

bool Check_Account( string user, string pass, string fileaccount )
{
	Init_DanhSach();
	Read_File_Account(fileaccount);
	bool check = false;
	acc p = NULL;
	switch( user[0] )
	{
		case 'a':
		case 'A':
			{
				p = A;
				break;
			}
		case 'b':
		case 'B':
			{
				p = B;
				break;
			}
		case 'c':
		case 'C':
			{
				p = C;
				break;
			}
		case 'd':
		case 'D':
			{
				p = D;
				break;
			}
		case 'e':
		case 'E':
			{
				p = E;
				break;
			}
		case 'f':
		case 'F':
			{
				p = F;
				break;
			}
		case 'g':
		case 'G':
			{
				p = G;
				break;
			}
		case 'h':
		case 'H':
			{
				p = H;
				break;
			}
		case 'i':
		case 'I':
			{
				p = I;
				break;
			}
		case 'j':
		case 'J':
			{
				p = J;
				break;
			}
		case 'k':
		case 'K':
			{
				p = K;
				break;
			}
		case 'l':
		case 'L':
			{
				p = L;
				break;
			}
		case 'm':
		case 'M':
			{
				p = M;
				break;
			}
		case 'n':
		case 'N':
			{
				p = N;
				break;
			}
		case 'o':
		case 'O':
			{
				p = O;
				break;
			}
		case 'p':
		case 'P':
			{
				p = P;
				break;
			}
		case 'q':
		case 'Q':
			{
				p = Q;
				break;
			}
		case 'r':
		case 'R':
			{
				p = R;
				break;
			}
		case 's':
		case 'S':
			{
				p = S;
				break;
			}
		case 't':
		case 'T':
			{
				p = T;
				break;
			}
		case 'u':
		case 'U':
			{
				p = U;
				break;
			}
		case 'v':
		case 'V':
			{
				p = V;
				break;
			}
		case 'w':
		case 'W':
			{
				p = W;
				break;
			}
		case 'x':
		case 'X':
			{
				p = X;
				break;
			}
		case 'y':
		case 'Y':
			{
				p = Y;
				break;
			}
		case 'z':
		case 'Z':
			{
				p = Z;
				break;
			}
	}
	while( p != NULL )
	{
		if( !user.compare(p->user) && !pass.compare(p->pass) )
		{
			check = true;
			break;
		}
		p = p->next;
	}
	return check;
}

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
		else if( kitu == DOWN )
		{
			gotoxy(--x,y);
			cout << " ";
			pass.erase(pass.length()-1,1);
			break;
		}
		else if( kitu == LEFT || kitu == RIGHT || kitu == UP )
		{
			gotoxy(--x,y);
			cout << " ";
			pass.erase(pass.length()-1,1);
			continue;
		}
		else if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!' )
        {
        	pass += kitu;
        	gotoxy(x++,y);
        	cout << '*';
		}
    }
    color_rectangle(96,27,20,3,Light_Green);
	insert_title(96,27,Bright_White,Light_Green,20,4,"LOGIN");
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
		else if( kitu == DOWN )
		{
			gotoxy(--x,y);
			cout << " ";
			user.erase(user.length()-1,1);
			break;
		}
		else if( kitu == UP || kitu == LEFT || kitu == RIGHT)
		{
			gotoxy(--x,y);
			cout << " ";
			user.erase(user.length()-1,1);
			continue;
		}
		else if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!')
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

//note
void Note_Acc( int x, int y, int width, int height, string note, int color,int &end)
{
	show_rectangle(x,y,width,height,color);
	color_rectangle(x+1,y+1,width,height-1,color);
	insert_title(x,y,color,Black,width,height+1,note);
	int key;
	key = getch();
	switch(key)
	{
		case ENTER: break;
		case ESC: end=0;
					break;
	}
}

void menu( string user )
{
	resizeConsole(1100, 630);
	ShowConsoleCursor(0);
	show_tittle(22,4);
	show_rectangle(1,1,130,32,Purple);
	insert_title(45,10,Bright_White ,Black,40,4,"STUDENT : " + user);
	show_rectangle(45,14,40,4,White);
	color_rectangle(46,15,40,3,White);
	insert_title(45,14,Aqua,White,40,5,"Lam Bai Thi");
	show_rectangle(45,19,40,4,Purple);
	insert_title(45,19,Red,Black,40,5,"XEM DIEM");
	show_rectangle(45,24,40,4,Purple);
	insert_title(45,24,Red,Black,40,5,"THOAT");
	char catkey;
	int number = 1;
	while( true )
	{
		catkey = getch();
	switch(catkey)
	{
		case UP:
			{
				if( number == 1 )
				{
					number = 3;
					show_rectangle(45,14,40,4,Purple);
					color_rectangle(46,15,40,3,Black);
					insert_title(45,14,Red,Black,40,5,"Lam Bai Thi");
					show_rectangle(45,24,40,4,White);
					color_rectangle(46,25,40,3,White);
					insert_title(45,24,Aqua,White,40,5,"THOAT");
				}
				else if( number == 2 )
				{
					number = 1;
					show_rectangle(45,14,40,4,White);
					color_rectangle(46,15,40,3,White);
					insert_title(45,14,Aqua,White,40,5,"Lam Bai Thi");
					show_rectangle(45,19,40,4,Purple);
					color_rectangle(46,20,40,3,Black);
					insert_title(45,19,Red,Black,40,5,"XEM DIEM");
				}
				else if( number == 3 )
				{
					number = 2;
					show_rectangle(45,19,40,4,White);
					color_rectangle(46,20,40,3,White);
					insert_title(45,19,Aqua,White,40,5,"XEM DIEM");
					show_rectangle(45,24,40,4,Purple);
					color_rectangle(46,25,40,3,Black);
					insert_title(45,24,Red,Black,40,5,"THOAT");
				}
				break;
			}
		case DOWN:
			{
				if( number == 3 )	
				{
					number = 1;
					show_rectangle(45,24,40,4,Purple);
					color_rectangle(46,25,40,3,Black);
					insert_title(45,24,Red,Black,40,5,"THOAT");
					show_rectangle(45,14,40,4,White);
					color_rectangle(46,15,40,3,White);
					insert_title(45,14,Aqua,White,40,5,"Lam Bai Thi");
				}
				else if( number == 2 )
				{
					number = 3;
					show_rectangle(45,19,40,4,Purple);
					color_rectangle(46,20,40,3,Black);
					insert_title(45,19,Red,Black,40,5,"XEM DIEM");
					show_rectangle(45,24,40,4,White);
					color_rectangle(46,25,40,3,White);
					insert_title(45,24,Aqua,White,40,5,"THOAT");
				}
				else if( number == 1 )
				{
					number = 2;
					show_rectangle(45,14,40,4,Purple);
					color_rectangle(46,15,40,3,Black);
					insert_title(45,14,Red,Black,40,5,"Lam Bai Thi");
					show_rectangle(45,19,40,4,White);
					color_rectangle(46,20,40,3,White);
					insert_title(45,19,Aqua,White,40,5,"XEM DIEM");
				}
				break;
			}
			
		case ENTER:
			{
				if( number == 3 )
				{
					system("cls");
					return;
				}
			}
	}
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
							menu(user);
						}
						else Note_Acc(40,16,40,4,"TAI KHOAN KHONG TON TAI!",Red,end);
						break;
					break;
			}
			case ESC : 
			{
				end = 0;
				break;
			}
			case UP:
				{
					color_rectangle(96,27,20,3,Purple);
					insert_title(96,27,Aqua,Black,20,4,"LOGIN");
					Insert_pass(pass,v,t);
					break;
				}
			case DOWN:
				{
					color_rectangle(96,27,20,3,Purple);
					insert_title(96,27,Aqua,Black,20,4,"LOGIN");
					Insert_user(user,pass,x,y,v,t);
					break;
				}
		}
	}
}
