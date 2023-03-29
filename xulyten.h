#include"function.h"
void Chu_Thich(){
	int x=wherex();
	int y=wherey();
	gotoxy(1,10);
	SetColor(2);
	cout<<"Chu thich:";
	cout<<setw(10)<<"Backspace: xoa 1 ky tu.";
	SetColor(15);
	gotoxy(x,y);
}

void Do_Hoa_Backspace(){
	gotoxy(wherex()-1,wherey());
	cout<<" ";
	gotoxy(wherex()-1,wherey());
}

string Xu_Ly_Ma(){
	char chu;
	string chuoi;
	do{
		chu=getch();
		if((chu>=65&&chu<=90)||(chu>=48&&chu<=57)){
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu>=97&&chu<=142){
			chu=chu-32;
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu==8){
			chuoi.pop_back();
			Do_Hoa_Backspace();
		}	
	}while(chu!=13);
	if(chuoi.size()<=15){
		cout<<"\nMa hop le.\n";
	}else{
		cout<<"\nMa khong hop le.\n";
		chuoi="";
	}
	return chuoi;
}

string Xu_Ly_Ten(){
	char chu;
	string chuoi;
	Chu_Thich();
	cout<<"Nhap ten: ";
	do{
		chu=getch();
		if(chu==32&&(chuoi[chuoi.size()-1]!=32)&&chuoi.size()!=0){
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu>=65&&chu<=90){
			if(chuoi[chuoi.size()-1]!=32||chuoi.size()!=0){
				chu=chu+32;	
			}
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu>=97&&chu<=142){
			if(chuoi[chuoi.size()-1]==32||chuoi.size()==0){
				chu=chu-32;	
			}
			cout<<chu;
			chuoi=chuoi+chu;	
			
		}else if(chu==8){
			chuoi.pop_back();
			Do_Hoa_Backspace();
		}
	}while(chu!=13);
	if(chuoi.size()<=50){
		cout<<"\nMa hop le.\n";
	}else{
		cout<<"\nMa khong hop le.\n";
		chuoi="";
	}
	return chuoi;
}
