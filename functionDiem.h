#include "function.h"
void InitializeDT(PTRDT &First){
	First =NULL;
}
PTRDT New_NodeDT(void){
	PTRDT p= new nodeDT;
	return p;
}
int EmptyDT(PTRDT First){
	if(First == NULL ) return TRUE;
	else return FALSE;
}
void Insert_FirstDT(PTRDT &First, DiemThi x){
	PTRDT p;
	p=New_NodeDT();
	p->dt=x;
	p->next=First;
	First=p;
}
void Insert_AfterDT(PTRDT &p, DiemThi x){
	PTRDT q;
		q=New_NodeDT();
		q->dt=x;
		q->next=p->next;
		p->next=q;

}
void Delete_FirstDT(PTRDT &First){
	PTRDT p;
		p=First;
		First=First->next;
		delete p;
} 
void Delete_AfterDT(PTRDT p){
	PTRDT q;
		q=p->next;
		p->next=q->next;
		delete q;

}
void Clear_ListDT(PTRDT &First){
	while(First!=NULL) Delete_FirstDT(First);	
}
void TraverseDT(PTRDT First)
{
	for(PTRDT p=First;p!=NULL;p=p->next){
		cout<<setw(20)<<p->dt.DIEM;
	}
} 
PTRDT SearchDT(PTRDT &First,DiemThi x){
	PTRDT p;
	for(p=First;p!=NULL&&p->dt.MMH!=x.MMH;p=p->next);
	return p;
}

void Edit_DiemDT(PTRDT &p,float x){
	p->dt.DIEM==x;
}
//////////////////////////////////////////////////
void Delete_InfoDT(PTRDT &First,string MMH){//sai
	PTRDT p,q;
	if(MMH==First->dt.MMH) Delete_FirstDT(First);
	else{
	for(p=First;p->next!=NULL&&p->next->dt.MMH!=MMH;p=p->next);
	if(p->next!=NULL) Delete_AfterDT(PTRDT p);
	}
}

