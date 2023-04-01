#include "function.h"

int EmptyMH(LISTMH &ds){
    return ds.n==0;
}

int Full(LISTMH &ds){
    return ds.n==MonMax;
}

int InsertMH(LISTMH &ds, int i, MonHoc mon){
    int j;
    if(i<0||i>ds.n||Full(ds)){
        return 0;
    }
    for(j=ds.n-1; j>=i; j--)
        ds.nodeMH[j+1]=ds.nodeMH[j];
    ds.nodeMH[i]=mon;
    ds.n++;
    return 1;
}

int DeleteMH(LISTMH &ds, int i){
    int j;
    if(i<0||i>=ds.n||EmptyMH(ds))
        return 0;
    for(j=i+1; j<ds.n; j++)
        ds.nodeMH[j-1]=ds.nodeMH[j];
    ds.n--;
    return 1;
}

void Traverse(LISTMH &ds){
    int i;
    if(EmptyMH(ds)){
        cout<<"\nDanh sach rong";
    }
    for(i=0; i<ds.n; i++){
        cout<<"\n"<<ds.nodeMH[i].MAMH<<"\t"<<ds.nodeMH[i].TENMH;
    }
}

int Search_X(LISTMH &ds, string x){
    for(int i=0; i<ds.n; i++){
        if(ds.nodeMH[i].MAMH==x||ds.nodeMH[i].TENMH==x)
            return i;
    }
    return -1;
}

