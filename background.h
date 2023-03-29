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
void insert_title(int x,int y,int color, int width, int hight, string title)
{
	SetColor(color);
	gotoxy(x + (width- title.length())/2 ,y + (hight - 1)/2);
	cout << title;
	SetColor(White);
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
	insert_title(86,14,Aqua,40,4," DANG NHAP ");
	show_rectangle(86,17,38,4,Purple);
	show_rectangle(86,22,38,4,Purple);
	SetColor(Blue);
	gotoxy(88, 19);
	cout << "User:";
	gotoxy(88, 24);
	cout << "Pass:";
	color_rectangle(96,27,20,3,Purple);
	insert_title(96,27,Aqua,20,4,"LOGIN");
	SetColor(Green);
	gotoxy(85,31);
	cout << "*Vui long khong nhap ki tu sau: | \ ~ !";
	SetColor(White);
}
void Khung_Lop(){
	resizeConsole(NGANG_KHUNG,DAI_KHUNG);
	for(int y=Y_TREN;y<=Y_DUOI;y++){
		//SetBGColor(15);
		//SetColor(0);
		SetColor(15);
		for(int x=X_TRAI-1;x<=X_PHAI+1;x++){
 			if(y==Y_TREN||y==Y_DUOI||y==LINE1||y==LINE2){
				gotoxy(x,y);
				cout<<n;
			}
			else if(x<=X_TRAI||x>=X_PHAI){
				gotoxy(x,y);
				cout<<n;
			}
			if((x==COLUMN1||x==COLUMN2||x==COLUMN3)&&y>LINE1){
				gotoxy(x,y);
				cout<<n;
			}
		}
	}
	gotoxy(60,5);
	cout<<"DANH SACH LOP";
	gotoxy(X_TRAI+(COLUMN1-X_TRAI)/2+2-3,LINE1+2);
	cout<<"STT";
	gotoxy(COLUMN1+(COLUMN2-COLUMN1)/2+2-6,LINE1+2);
	cout<<"MA LOP";
	gotoxy(COLUMN2+(COLUMN3-COLUMN2)/2+2-6,LINE1+2);
	cout<<"TEN LOP";
	gotoxy(COLUMN3+(X_PHAI-COLUMN3)/2+2-6,LINE1+2);
	cout<<"NIEN KHOA";
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
