#include<iostream>
#include "mylib.h"

using namespace std;

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
void insert_title(int x,int y,int color, int width, int hight, string title)
{
	SetColor(color);
	gotoxy(x + (width- title.length())/2 ,y + (hight - 1)/2);
	cout << title;
	SetColor(White);
}

// man hinh login
void console_loggin()
{
	resizeConsole(1100, 630);
	system("cls");
	show_tittle(22,4);
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(85,13,40,17, Red);
	color_rectangle(86,14,40,3,Red);
	insert_title(86,14,Aqua,40,4," DANG NHAP ");
	show_rectangle(86,17,38,4,Red);
	show_rectangle(86,22,38,4,Red);
	SetColor(Blue);
	gotoxy(88, 19);
	cout << "User:";
	gotoxy(88, 24);
	cout << "Pass:";
	color_rectangle(96,27,20,3,Red);
	insert_title(96,27,Aqua,20,4,"LOGIN");
	SetColor(Green);
	gotoxy(85,31);
	cout << "*Vui long khong nhap ki tu sau: | \ ~ !";
	SetColor(White);
}

void Insert_Loggin()
{
	string user, pass;
	gotoxy(94, 19);
	char kitu;
	while( true )
	{
		kitu = getch();
		if( kitu == '\r' ) break;
		if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!')
		{
			user += kitu;
			putchar( kitu );
		}
	}
	gotoxy(94,24);
	while (true) {
        kitu = getch();
        ShowConsoleCursor(0);
        if (kitu == '\r') {
            break;
        }
        if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!' )
        {
        	pass += kitu;
        	putchar('*');
		}
    }
    color_rectangle(96,27,20,3,Bright_White);
	insert_title(96,27,Bright_White,20,4,"LOGIN");
}
int main()
{
	string user, pass;
	console_loggin();
	Insert_Loggin();
	getch();
	return 0;
}
