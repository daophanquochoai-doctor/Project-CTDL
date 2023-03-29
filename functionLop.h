#include "function.h"
int EmptyL(DSLOP dslop){
	return	dslop.n==0? TRUE:FALSE;
}										
void InsertL(DSLOP &dslop, Lop x){
	while(dslop.n<LopMax){
		dslop.nodeL[dslop.n]=new Lop;
		*dslop.nodeL[dslop.n]=x;
		dslop.n++;
	}
}
void Delete_Item(DSLOP &dslop,int i){
	delete dslop.nodeL[i];
	for(int j=i+1;j<dslop.n;j++){
		dslop.nodeL[j-1]=dslop.nodeL[j];
		dslop.n--;
	}
}	
int Search_NameL(DSLOP dslop,string x){
	for(int i=0;i<=dslop.n;i++){
		if(dslop.nodeL[i]->TENLOP==x) return i; 
	}
	return -1;
}
int Search_IDL(DSLOP dslop,string x){
	for(int i=0;i<=dslop.n;i++){
		if(dslop.nodeL[i]->MALOP==x) return i; 
	}
	return -1;
}		
void Delete_IDL(DSLOP &dslop,string x){
	int i=Search_IDL(dslop,x);
	if(i==-1) BaoLoi("Khong ton tai id nay.");
	else Delete_Item(dslop,i);
}
void Delete_NameL(DSLOP &dslop,string x){
	int i=Search_NameL(dslop,x);
	if(i==-1) BaoLoi("Khong ton tai ten nay.");
	else Delete_Item(dslop,i);
}
void Edit_NameL(DSLOP &dslop,Lop x){
	int i=Search_IDL(dslop,x.MALOP);
	dslop.nodeL[i]->TENLOP=x.TENLOP;
}
void TraverseL(DSLOP dslop){
		cout<<setw(20)<<"STT";
		cout<<setw(20)<<"MA LOP";
		cout<<setw(20)<<"TEN LOP";
		cout<<setw(20)<<"NIEN KHOA";
	for(int i=0;i<dslop.n;i++){
		cout<<i+1<<"."<<setw(30);
		cout<<setw(20)<<dslop.nodeL[i]->MALOP;
		cout<<setw(20)<<dslop.nodeL[i]->TENLOP;
		cout<<setw(20)<<dslop.nodeL[i]->NIENKHOA;
	}
}
int Traverse_Nienkhoa(DSLOP dslop,string x){
	for(int i=0;i<=dslop.n;i++){
		if(dslop.nodeL[i]->NIENKHOA==x) {
			cout<<setw(20)<<dslop.nodeL[i]->MALOP;
			cout<<setw(20)<<dslop.nodeL[i]->TENLOP;
	
	}
	}
	return -1;
}	
