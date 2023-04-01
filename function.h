#include"khaibaobien.h"
//=============================================================
//DIEM THI - ds lien ket don(PTRDT)
void InitializeDT(PTRDT &First);				//Khoi tao
PTRDT New_NodeDT(void);							//Cap phat vung nho
int EmptyDT(PTRDT First);						//kiem tra rong
void Insert_FirstDT(PTRDT &First,DiemThi x);
void Insert_AfterDT(PTRDT &p,DiemThi x);			//them nut moi vao sau nut co dia chi p
void Insert_OrderDT(PTRDT &First,DiemThi x);
void Delete_FirstDT(PTRDT &First);
void Delete_AfterDT(PTRDT p);					//xoa nut o sau nut p
void Delete_InfoDT(PTRDT &First,float x);
void Clear_ListDT(PTRDT &First);				//xoa tat ca nut
void TraverseDT(PTRDT First);					//duyet danh sach
void Ascending_SortDT(PTRDT &First);	//sap xep tang dang
void Descending_SortDT(PTRDT &First);	//sap xep giam dang 
PTRDT SearchDT(PTRDT &First,DiemThi x);
void Edit_DiemDT(PTRDT &p,float x);
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
string Xu_Ly_Ma();//xu ly ma sv, ma lop va ma mon hoc(dung chung 1 ham)
//-SinhVien---
string Xu_Ly_TenSV();
string Xu_Ly_Ma_So_SV();
string Xu_Ly_Phai();
//-Lop----
string Xu_Ly_TenL();
string Xu_Ly_Nien_Khoa();
//-MonHoc---
string Xu_Ly_TenMH();
//-Diem--
void Xu_Ly_Diem(float &DIEM);
//-CauHoi--
void Xu_Ly_ID(int ID);
//=============================================================
//password
// xuat nhap file
void Read_File_ListL(DSLOP &dslop,string tenfile);

