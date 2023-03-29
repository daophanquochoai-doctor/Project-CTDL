#include "functionDiem.h"

char Menu(){
	char chucnang;
	do{	
		clrscr();
		cout<<"=========================================\n";
		cout<<"1. Tao ds diem.\n";
		cout<<"2. Them vao danh sach diem.\n";
		cout<<"3. Them vao vi tri tuy chon.";
		cout<<"4. Xoa phan tu dau tien.\n";
		cout<<"5. Xoa phan tu tuy chon.\n";
		cout<<"6. Xoa theo Ma mon hoc.\n";
		cout<<"7. Tim kiem Mon hoc co diem.\n";
		cout<<"8. Sua diem.\n";
		cout<<"9. In danh sach diem.\n";
		cout<<"0. Ket thuc chuong trinh.\n";
		cout<<"=========================================\n";
		cout<<"Chon chuc nang: ";
		chucnang=getche();
	}while(chucnang<'0'||chucnang>'9');
	cout<<"\n=========================================\n";
	return chucnang;
}
int main(){
	float x=10;
	int n=0;
	string chuoi;
	char chucnang;
	DiemThi diem;
	PTRDT dsdiem,tam;
	InitializeDT(dsdiem);
	do{
		chucnang=Menu();
		switch(chucnang){
		case '1':
			cout<<"Nhap so luong mon: ";
			cin>>n;
			for(int i=0;i<n;i++){
				cout<<"Nhap Ma Mon Hoc: ";
				cin>>diem.MMH;
				cout<<"Nhap diem: ";
				cin>>diem.DIEM;
				Insert_FirstDT(dsdiem,diem);

			}
			break;
		case '2':
			break;
		case '3':

			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			cout<<"Nhap ma mon hoc: ";
			cin>>chuoi;
			Delete_InfoDT(dsdiem,chuoi);
			break;
		case '9':
			gotoxy(2,15);
			TraverseDT(dsdiem);
			cin>>x;
			break;
		default:
			break;
		}
		
	}while(chucnang!='0');
	return 0;
}
