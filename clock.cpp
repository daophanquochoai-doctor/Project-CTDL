#include<iostream>
#include<fstream>
#include "background.h"
#include<thread>
//#include "ReadFile.h"


using namespace std;

bool stop = false;

void Do_Exam()
{
	ShowConsoleCursor(0);
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(15,8,100,9,Aqua);
	show_rectangle(15,18,45,3,White);
	show_rectangle(70,18,45,3,Purple);
	show_rectangle(15,22,45,3,Purple);
	show_rectangle(70,22,45,3,Purple);
    show_rectangle(107, 5, 8, 2, Red);
    gotoxy(111,6);
    cout << ":";
	int catkey;
	char choose = 'A';
	while( true )
	{
		catkey = getch();
		switch( catkey )
		{
			case DOWN :
				{
					if( choose == 'A' )
					{
						choose = 'C';
						show_rectangle(15,18,45,3,Purple);
						show_rectangle(15,22,45,3,White);
					}
					else if( choose == 'B' )
					{
						choose = 'D';
						show_rectangle(70,18,45,3,Purple);
						show_rectangle(70,22,45,3,White);
					}
					break;
				}
			case UP:
				{
						if( choose == 'C' )
					{
						choose = 'A';
						show_rectangle(15,18,45,3,White);
						show_rectangle(15,22,45,3,Purple);
					}
					else if( choose == 'D' )
					{
						choose = 'B';
						show_rectangle(70,18,45,3,White);
						show_rectangle(70,22,45,3,Purple);
					}
					break;
				}
			case RIGHT:
				{
					if( choose == 'A')
					{
						choose = 'B';
						show_rectangle(15,18,45,3,Purple);
						show_rectangle(70,18,45,3,White);
					}
					if( choose == 'C')
					{
						choose = 'D';
						show_rectangle(15,22,45,3,Purple);
						show_rectangle(70,22,45,3,White);
					}
					break;
				}
			case LEFT:
				{
					if( choose == 'B')
					{
						choose = 'A';
						show_rectangle(15,18,45,3,White);
						show_rectangle(70,18,45,3,Purple);
					}
					if( choose == 'D')
					{
						choose = 'C';
						show_rectangle(15,22,45,3,White);
						show_rectangle(70,22,45,3,Purple);
					}
					break;
				}
			case ENTER:
				{
					stop = true;
					return;
				}
		}
	}
}

void startTimerJob(int time){
	int p = 0, s = 0;
	while( (time != 0 || p != 0 || s != 0) && !stop)
	{
		if( time >= 10 )
		{
			gotoxy(109,6);
		}
		else{
			gotoxy(109,6);
			cout <<0;
			gotoxy(110,6);
		}
		cout << time;
		gotoxy(112,6);
		cout << p;
		gotoxy(113,6);
		cout << s;
		if( p == 0 && s == 0 )
		{
			time --;
			p = 5;
			s = 9;
		}
		else if( s == 0)
		{
			p--;
			s = 9;
		}
		else s--;
		Sleep(980);
	}

}
void startTimer(){
	thread timer;
	timer=thread(startTimerJob,10); ShowConsoleCursor(0);
	Do_Exam();  
	timer.join();
}
int main()
{
	resizeConsole(1100, 630);
startTimer();
//startTimerJob(10);
	getch();
	return 0;
}

