#include"khaibaobien.h"
//=============================================================
//DIEM THI - ds lien ket don(PTRDT)
void InitializeDT(PTRDT &First);				//Khoi tao
PTRDT NewnodeDT(void);							//Cap phat vung nho
int EmptyDT(PTRDT First);						//kiem tra rong
void Insert_FirstDT(PTRDT &First,int x);
void Insert_LastDT(PTRDT &First,int x);			// co the khong dung 
void Insert_AfterDT(PTRDT p,int x);				//them nut moi vao sau nut co dia chi p
void Search_infoDT(PTRDT First,int x);
void Delete_FirstDT(PTRDT &First);
void Delete_LastDT(PTRDT &First);				// co the khong dung 
void Delete_AfterDT(PTRDT p);					//xoa nut o sau nut p
void Delete_InfoDT(PTRDT &First,int x);
void Clear_ListDT(PTRDT &First);				//xoa tat ca nut
void TraverseDT(PTRDT First);					//duyet danh sach
void Selection_Ascending_SortDT(PTRDT &First);	//sap xep tang dang
void Selection_Descending_SortDT(PTRDT &First);	//sap xep giam dang 
//============================================================
//SINH VIEN - ds lien ket don(PTRSV) 
void InitializeSV(PTRSV &First);//Khoi tao
PTRSV NewnodeSV(void);							//Cap phat vung nho
int EmptySV(PTRSV First);						//kiem tra rong
void Insert_FirstSV(PTRSV &First,int x);
void Insert_LastSV(PTRSV &First,int x);			// co the khong dung 
void Insert_AfterSV(PTRSV p,int x);
void Search_infoSV(PTRSV First,int x);
void Delete_FirstSV(PTRSV &First);
void Delete_LastSV(PTRSV &First);				// co the khong dung 
void Delete_AfterSV(PTRSV p);
void Delete_InfoSV(PTRSV &First,int x);
void Clear_ListSV(PTRSV &First);
void TraverseSV(PTRSV First);
void Selection_Ascending_SortSV(PTRSV &First);	// sap xep tang dang
void Selection_Descending_SortSV(PTRDT &First);	//sap xep giam dan
//=============================================================
//MON HOC- ds tuyen tinh(DSMON)
int EmptyMH(LISTMH &ds);						//Tra ve so phan tu cua list
int Full(LISTMH &ds);							//Tra ve so phan tu cua list
int InsertMH(LISTMH &ds,int i,MonHoc mon);		//Them vao vi tri i
int DeleteMH(LISTMH &ds,int i);					//Xoa phan tu vi tri i
void Traverse(LISTMH &ds);					//In danh sach
int Search_X(LISTMH &ds,MonHoc X);			//Tra ve vi tri cua X
//=============================================================
//LOP- ds tuyen tinh/mang con tro (DSLOP)

//=============================================================
//CAU HOI- Cay nhi phan tim kiem(NODEPTRCH)
//=============================================================
//DoHoa
//=============================================================
//Luong thoi gian(THREAD)
//=============================================================
//xu ly du lieu nhap
void Xu_Ly_Ma(string &ma);//xu ly ma sv, ma lop va ma mon hoc(dung chung 1 ham)
//-SinhVien---
void Xu_Ly_TenSV(string &tensv);
void Xu_Ly_Ma_So_SV(string &mssv);
void Xu_Ly_Phai(string &phai);
//-Lop----
void Xu_Ly_TenL(string &tenlop);
void Xu_Ly_Nien_Khoa(string &nienkhoa);
//-MonHoc---
void Xu_Ly_TenMH(string &tenmh);
//-Diem--
void Xu_Ly_Diem(float &DIEM);
//-CauHoi--
void Xu_Ly_ID(int ID);
//=============================================================
//password
//ham main


