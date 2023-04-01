#include <thread>
#include <unistd.h>
#include <iostream>
#include "background.h"
#include <time.h>

using namespace std;
 int stop=0;  // bien dwfng ca 2 thread
void run(){
	char kt;
	while((kt=getch())!=27 && stop==0){  // an ESC de ket thuc
		gotoxy(0,1);   cout <<kt;
	}
	stop=1;
	if (kt==27) cout<<"\nDung chuong trinh do user ."<<endl;
	else cout<<"\nDung chuong trinh do het thoi gian ."<<endl;
}
void startTimerJob(int time){
	 int x = 100, y = 10;
    int p = 0, s = 0;
    int color = Aqua;
    do
    {
        if (time == 15)
        {
            color = Red;
            color_rectangle(x + 1, y, 8, 2, Red);
        }
        ShowConsoleCursor(0);
        show_rectangle(x, y, 8, 2, color);
        gotoxy(x + 4, y + 1);
        cout << ":";
        if (time >= 10)
        {
            gotoxy(x + 2, y + 1);
        }
        else
        {
            gotoxy(x + 2, y + 1);
            cout << 0;
            gotoxy(x + 3, y + 1);
        }
        cout << time;
        gotoxy(x + 5, y + 1);
        cout << p;
        gotoxy(x + 6, y + 1);
        cout << s;
        if (p == 0 && s == 0)
        {
            time--;
            p = 5;
            s = 9;
        }
        else if (s == 0)
        {
            p--;
            s = 9;
        }
        else
            s--;
        Sleep(1);
    } while (time != 0 || p != 0 || s != 0);

}
void startTimer(){
	thread timer;
	timer=thread(startTimerJob,10); // tao thread cho Ch Trinh con startTimerJob chay trong 10 giay
	
	run();  // luong chuong trinh chinh cua ta
	timer.join();  // After a call to this function, the thread object becomes non-joinable and can be destroyed safely
}
int main(){
	startTimer();	
}

