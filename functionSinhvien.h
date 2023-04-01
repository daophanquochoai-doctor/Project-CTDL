#include "khaibaobien.h"

void InitializeSV(PTRSV &First){
    First=NULL;
}

PTRSV NewnodeSV(void){
    PTRSV p=new nodeSV;
    return p;
}

int EmptySV(PTRSV First){
    return(First==NULL);
}

void Insert_FisrtSV(PTRSV &First, SinhVien x){
    PTRSV p;
    p=NewnodeSV();
    p->sv=x;
    p->next=First;
    First=p;
}

void Insert_AfterSV(PTRSV p, SinhVien x){
    PTRSV q;
    if(p==NULL) 
        cout<<"\nKhong the thuc hien";
    else{
        q=NewnodeSV();
        q->sv=x;
        q->next=p->next;
        p->next=q;
    }
}

void Insert_Order(PTRSV &First, SinhVien x){
    PTRSV p, t, s;
    p=NewnodeSV();
    p->sv=x;
    for(s=First; s!=NULL && s->sv.MASV<x.MASV; t=s, s=s->next);
    if(s==First){
        p->next=First;
        First=p;
    }else{
        p->next=s;
        t->next=p;
    }
}

void Delete_FirstSV(PTRSV &First){
    PTRSV p;
    if(EmptySV(First)){
        cout<<"\nDanh sach rong";
    }
    p=First;
    First=p->next;
    delete p;
}

void Delete_AfterSV(PTRSV p){
    PTRSV q;
    if((p==NULL)||(p->next==NULL))
        cout<<"\nKhong the thuc hien";
    q=p->next;
    p->next=q->next;
    delete q;
}

PTRSV SearchSV(PTRSV First, string x){
    PTRSV p;
    for(p=First; p!=NULL; p=p->next){
        if(p->sv.MASV==x)
            return p;
    }
    return NULL;
}

void Search_DeleteSV(PTRSV &First, string x){
    PTRSV p;
    if(EmptySV(First)||SearchSV(First, x)==NULL)
        cout<<"\nKhong ton tai "<<x;
    else if(First->sv.MASV==x)
        Delete_FirstSV(First);
    else{
        for(p=First; p->next!=NULL; ){
            if(p->next->sv.MASV==x)
                Delete_AfterSV(p);
            else p=p->next;
        }
    }
}

void Clear_ListSV(PTRSV &First){
    PTRSV p;
    while(First!=NULL){
        p=First;
        First=First->next;
        delete p;
    }
}

void TraverseSV(PTRSV First){
    PTRSV p;
    int stt=0;
    if(p==NULL)
        cout<<"\nKhong co phan tu trong danh sach";
    for(p=First; p!=NULL; p=p->next){
        stt++;
        cout<<"\n"<<stt<<"\t"<<p->sv.HO<<"\t"<<p->sv.TEN<<"\t"<<p->sv.MASV<<"\t"<<p->sv.PHAI;
    }
}

void Selection_Ascending_SortSV(PTRSV &First){
    PTRSV p, q, pmin;
    int min;
    for(p=First; p->next!=NULL; p=p->next){
        min=p->sv.contro_dsdiem->dt.Diem;
        pmin=p;
        for(q=p->next; q!=NULL; q=q->next){
            if(q->sv.contro_dsdiem->dt.Diem<min){
                min=q->sv.contro_dsdiem->dt.Diem;
                pmin=q;
            }
        }
        pmin->sv=p->sv;
        p->sv.contro_dsdiem->dt.Diem=min;
    }
}

void Selection_Descending_SortSV(PTRSV &First){
    PTRSV p, q, pmax;
    int max;
    for(p=First; p->next!=NULL; p=p->next){
        max=p->sv.contro_dsdiem->dt.Diem;
        pmax=p;
        for(q=p->next; q!=NULL; q=q->next){
            if(q->sv.contro_dsdiem->dt.Diem>max){
                max=q->sv.contro_dsdiem->dt.Diem;
                pmax=q;
            }
        }
        pmax->sv=p->sv;
        p->sv.contro_dsdiem->dt.Diem=max;
    }
}