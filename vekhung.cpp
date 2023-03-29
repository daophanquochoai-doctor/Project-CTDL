#include<iostream>
#include "mylib.h"
using namespace std;

#define Y_TREN 3
#define Y_DUOI 23
#define X_TRAI 5
#define X_PHAI 65

char n=176;
void VeKhung(){
	for(int y=Y_TREN;y<=Y_DUOI;y++){
		for(int x=X_TRAI-1;x<=X_PHAI+1;x++){
 			if(y==Y_TREN||y==Y_DUOI){
				gotoxy(x,y);
				cout<<n;
			}
			else if(x<=X_TRAI||x>=X_PHAI){
				gotoxy(x,y);
				cout<<n;
			}
		}
	}
}
int main(){
	VeKhung();
	return 0;
}
