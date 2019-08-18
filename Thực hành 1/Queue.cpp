#include<stdio.h>
int soTT=1000;
//Khai bao cau truc benh nhan
typedef struct BenhNhan
{
	int stt;
	char hoTen[40+1];
	int tuoi;
}BN;
//Nhap thong tin benh nhan
void Nhap(BN &bn)
{
	bn.stt = ++soTT;
	printf("\nHo ten= ");
	gets(bn.hoTen); gets(bn.hoTen);
	printf("Tuoi= ");
	scanf("%d", &bn.tuoi);
}
//Xuat thong tin benh nhan
void Xuat(BN bn)
{
	printf("\nSTT: %d", bn.stt);
	printf("\nHo ten= %s",bn.hoTen);
	printf("\nTuoi= %d", bn.tuoi);
}
//Khai bao cau truc hang doi
struct Node
{
	BN info;
	struct Node* next;
};
typedef struct Node* QUEUE;
//Khoi dong hang doi
void Init(QUEUE &q)
{
	q = NULL;
}
//Kiem tra hang doi co rong hay khong 
int IsEmpty(QUEUE q)
{
	return (q == NULL);
}
//Tao mot nut trong hang doi
QUEUE CreateNode(BN x)
{
	QUEUE p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
//Them mot nut vao hang doi
void EnQueue(QUEUE &q, BN x)
{
	QUEUE p = CreateNode(x);
	if (IsEmpty(q))
		q = p;
	else
	{
		QUEUE pTail = q;
		while (pTail->next)
			pTail = pTail->next;
		pTail->next = p;
	}
}
//Xoa mot nut trong hang doi
BN DeQueue(QUEUE &q)
{
	if (!IsEmpty(q))	//  n?u không r?ng
	{
		BN x = q->info;
		QUEUE pDel = q;
		q = q->next;
		delete pDel;
		return x;
	}
	return NULL;
}
//Them mot benh nhan
int ThemMotBN(QUEUE &q)
{
	BN bn;
	printf("\nMoi nhap benh nhan can them ");
	Nhap(bn);
	EnQueue(q, bn);
	return bn.stt;
}
//Nhap so nut cua hang doi
void Nhap(int &n)
{
	do
	{
		printf("\nMoi nhap (n>0) n= ");
		scanf("%d", &n);
		if (n <= 0)
			printf("\nBan nhap sai, moi nhap lai..");
	} while (n <= 0);
}
//Nhap du lieu cua cac nut vao hang doi
void InputQueue(QUEUE &q)
{
	int n; Nhap(n);
	for (int i = 0; i < n; i++)
	{
		BN x;
		printf("\nNhap benh nhan thu %d", i + 1);
		Nhap(x);
		EnQueue(q, x);
	}
}
int BenhNhanTiepTheo(QUEUE &q)
{
	BN bn= DeQueue(q);
	if (bn.stt == -1)
		printf("\nDanh sach rong");
	else
	{
		printf("\nBenh nhan tiep theo la: ");
		Xuat(bn);
	}
	return bn.stt;
}
void Xuat()
{
	for (int i = 156; i <= 255; i++)
		printf("\t%d:%c", i, i);
	printf("\n");
	printf("%c%c%c%c%c", 218, 196, 196, 196, 194);
}
int main()
{
	int sttTam = soTT;
	QUEUE q;	Init(q);	InputQueue(q);
	int stt = ThemMotBN(q);	printf("\nSo thu tu: %d", stt);
	int sttDaKham=BenhNhanTiepTheo(q);
	if (sttDaKham == -1)
		printf("\nDanh sach rong");
	else
		printf("\nSo benh nhan chua kham: %d", stt - sttDaKham);
	printf("\nSo nguoi da kham: %d", sttDaKham - sttTam);*/
	Xuat();
	printf("\n");
}

