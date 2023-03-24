#include<iostream>
#include<string.h>
#include<random>
#include<fstream>
#include "khaibaobien.h"

#define MAX 1000000
using namespace std;

int Array_ID[MAX];
int counter = 1;
string filecauhoi = "cauhoi.txt";

//khoi tao mang ID
void InitArray_ID( )
{
	for( int i = 1 ; i <= MAX ; i++ )
	{
		Array_ID[i] = i;
	}
}

//khoi tao nut
void Initlize( NODEPTRCH &root ){
	root = NULL;
}

//Random ID
int Random_ID( )
{
	int	ID = rand() % (MAX-counter) + counter;
	swap(Array_ID[counter] , Array_ID[ID]);
	counter++;
	return Array_ID[counter-1];
}

// tao node
CauHoi Create_CauHoi( string mmh, string noidung, string A, string B, string C, string D, string dapan )
{
	CauHoi p;
	p.ID = Random_ID();
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

//doc cau hoi tu file
void Read_File_CauHoi(NODEPTRCH& root, string filecauhoi) {
    ifstream fin(filecauhoi);
    if (!fin.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
	InitArray_ID();
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

//viet cau hoi vao file
void Write_File_CauHoi( NODEPTRCH root, string filecauhoi ){
	ofstream ofn(filecauhoi, ios::ate );
    if (!ofn.is_open()) {
        cout << "Khong the mo file!";
        return;
    }
	const int STACKSIZE = 1000000;
   	NODEPTRCH Stack[STACKSIZE];
   	int sp=  -1;	// Khoi tao Stack rong
   	NODEPTRCH p=root;
   	while (p!=NULL )
   	{
		ofn << p->cauhoi.mmh << '|'<< p->cauhoi.noidung << '|' << p->cauhoi.A << '|' << p->cauhoi.B << '|' << p->cauhoi.C << '|' << p->cauhoi.D << '|' << p->cauhoi.dapan << '|' << endl;
      	if (p->right != NULL)
	 	Stack[++sp]= p->right;
     	if (p->left != NULL)
		p=p->left;
      	else  if (sp==-1)        break;
	    else	p=Stack[sp--];
	}
	ofn.close();
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

int main()
{
    return 0;
}

