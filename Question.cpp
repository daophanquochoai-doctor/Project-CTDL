#include<iostream>
#include<string.h>
#include<random>
#include<fstream>
#include "khaibaobien.h"

using namespace std;

string filecauhoi = "cauhoi.txt";

//khoi tao nut
void Initlize( NODEPTRCH &root ){
	root = NULL;
}

int Random( int Array[], int Soluong, int dem )
{
	int	ID = rand() % (Soluong-dem) + dem;
	swap(Array[dem] , Array[ID]);
	dem++;
	return Array[dem-1];
}

// tao node
CauHoi Create_CauHoi( string mmh, string noidung, string A, string B, string C, string D, string dapan )
{
	CauHoi p;
	p.ID = Random(Array_ID, MAX, counter);
	p.mmh = mmh;
	p.noidung = noidung;
	p.A = A;
	p.B = B;
	p.C = C;
	p.D = D;
	p.dapan = dapan;
	return p;
}

//them vao nut
void Insert_node( NODEPTRCH &root, CauHoi cauhoi ){
	if( root == NULL )
	{
		root = new nodeCH;
		root->cauhoi = cauhoi;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if( cauhoi.ID < root->cauhoi.ID )	Insert_node(root->left, cauhoi);
		else if( cauhoi.ID > root->cauhoi.ID ) Insert_node(root->right, cauhoi);
	}
}

//tao 1 cau hoi vao tree
void Create_node( NODEPTRCH &root )
{
	string	mmh, noidung, A, B, C, D, dapan;
	cout << "Nhap mmh:";
	getline(cin,mmh);
	cout << "Nhap noi dung cau hoi: ";
	getline(cin,noidung);
	cout << "Nhap dap an A: ";
	getline(cin,A);
	cout << "Nhap dap an B: ";
	getline(cin,B);
	cout << "Nhap dap an C: ";
	getline(cin,C);
	cout << "Nhap dap an D: ";
	getline(cin,D);
	cout << "Nhap dap an: ";
	getline(cin, dapan);
	CauHoi cauhoi = Create_CauHoi(mmh,noidung,A,B,C,D,dapan);
	Insert_node(root, cauhoi);
}

//doc cau hoi tu file
void Read_File_CauHoi(NODEPTRCH& root, string filecauhoi) {
    InitArray_ID();
    ifstream fin(filecauhoi);
    if (!fin.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string mmh, noidung, A, B, C, D, dapan;
        getline(iss, mmh, '|');
        getline(iss, noidung, '|');
        getline(iss, A, '|');
        getline(iss, B, '|');
        getline(iss, C, '|');
        getline(iss, D, '|');
        getline(iss, dapan, '|');

        CauHoi cauhoi = Create_CauHoi(mmh, noidung, A, B, C, D, dapan);
        Insert_node(root, cauhoi);
    }

    fin.close();
}

//in tree theo left node right
void Traverse_LNR( NODEPTRCH root )
{
	NODEPTRCH p = root;
	if( p != NULL )
	{
		Traverse_LNR(p->left);
		cout << p->cauhoi.ID << endl << p->cauhoi.mmh << endl << p->cauhoi.noidung << endl << p->cauhoi.A << endl << p->cauhoi.B << endl << p->cauhoi.C << endl << p->cauhoi.D << endl << p->cauhoi.dapan << endl << "==================" << endl;
		Traverse_LNR(p->right);
	}
}

//viet cau hoi vao file
void Write_File_CauHoi( NODEPTRCH root, string filecauhoi ){
	ofstream ofn(filecauhoi, ios::out );
    if (!ofn.is_open()) {
        cout << "Khong the mo file!";
        return;
    }
	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        ofn << p->cauhoi.mmh << '|'<< p->cauhoi.noidung << '|' << p->cauhoi.A << '|' << p->cauhoi.B << '|' << p->cauhoi.C << '|' << p->cauhoi.D << '|' << p->cauhoi.dapan << '|' << endl;   // “xu ly nút p”
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }
	ofn.close();
}

//search mmh
NODEPTRCH Search( NODEPTRCH root, int x)
{
   	NODEPTRCH p;   p = root;
   	while (p != NULL && p->cauhoi.ID !=x)
      if(x < p->cauhoi.ID)
             p = p->left;
      else
            p = p->right;
	return(p); 
}

// tao de thi
void Create_Exam( NODEPTRCH root, int socau, string mmh )
{
    // CauHoi *Cau = new CauHoi;
    CauHoi Cau[100];
    int dem = 1;
    const int STACKSIZE = 1000000;
   	NODEPTRCH Stack[STACKSIZE];
   	int sp=  -1;	// Khoi tao Stack rong
   	NODEPTRCH p=root;
   	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        Cau[dem].ID = p->cauhoi.ID;
        Cau[dem].mmh = p->cauhoi.mmh;
        Cau[dem].noidung = p->cauhoi.noidung;
        Cau[dem].A = p->cauhoi.A;
        Cau[dem].B = p->cauhoi.B;
        Cau[dem].C = p->cauhoi.C;
        Cau[dem].D = p->cauhoi.D;
        Cau[dem].dapan = p->cauhoi.dapan;
        dem ++;
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }
    // int Array_mmh[dem];
    // for( int i = 1 ; i < dem ;  i++ )
    // {
    //     Array_mmh[i] = i;
    // }
    // int counter_mmh = 1;
    for( int ID = 1; ID < socau ; ID++ )
    {
        // int ID = Random(Array_mmh, dem-1,counter_mmh );
        cout << Cau[ID].ID << " " << Cau[ID].noidung << endl;
    }

}


int main()
{
    NODEPTRCH root;
    system("cls");
    Initlize(root);
    Read_File_CauHoi(root,filecauhoi);
    // Traverse_LNR(root);
    // Create_node(root);
    // Traverse_LNR(root);
    // Write_File_CauHoi(root, filecauhoi);
    Create_Exam(root, 3, "1");
    return 0;
}

