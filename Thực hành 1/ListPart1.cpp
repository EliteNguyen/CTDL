#include<stdio.h>
#include<conio.h>
#define NULL 0
//Ham khai bao cau truc danh sach lien ket don
struct Node
{
	int info;
	struct Node *next;
	
};
typedef Node* NODEPTR;
//Ham khoi dong danh sach lien ket hay con goi la tac vu Init
void Init(NODEPTR &phead)
{
	phead = NULL;
}
//Ham tao mot nut hay cung cap 1 bien dong la mot nut cho danh sach lk-tao nut co du lieu x
NODEPTR CreateNode(int x)
{
	NODEPTR p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
//Ham them mot node vao dau dslk
void InsertFirst(NODEPTR &phead, int x)
{
	NODEPTR p = CreateNode(x);
	p->next = phead;
	phead = p;
}
//Ham nhap so luong nut trong danh sach lk
void Nhap(int &n)
{
	do
	{
		printf("\nMoi nhap (n>0) n= ");
		scanf("%d", &n);
		if (n <= 0)
		printf("Ban nhap sai, moi nhap lai...");
	}while (n <= 0);
}
//Ham nhap du lieu vao danh sach lk
void InputList(NODEPTR &phead)
{
	int n; Nhap(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		printf("\nMoi nhap gia tri node thu %d: ", i + 1);
		scanf("%d", &x);
		InsertFirst(phead, x);
	}
}
//Ham duyet dslk, hien thi thong tin cac nut
void ShowList2(NODEPTR phead)
{
	for(NODEPTR p = phead; p!=NULL ; p = p->next)
		printf("%4d", p->info);
}
//Ham them mot nut co noi dung x ngay sau nut p
void InsertAfter(NODEPTR p, int x)
{
	NODEPTR temp;
	if (p!=NULL)
	{
		temp = CreateNode(x);
		temp->next = p->next;
		p->next = temp;
	}
}
//Ham the nut co noi dung y sau nut co noi dung x
void Insert_Y_After_X(NODEPTR phead, int x, int y)
{
	NODEPTR p = phead;
	while (p!=NULL)
	{
		if (p->info == x)
		{
			InsertAfter(p, y);
			p = p->next;
		}
		p = p->next;
	}
}
//Ham dem so nut trong dslk 
int Count(NODEPTR phead)
{
	int dem = 0;
	NODEPTR p = phead; //int i=0;
	while (p != NULL) //while(i<n)
	{
		dem++; //dem++;
		p = p->next; //i++;
	}
	return dem;
}
//Ham Xuat ra thong tin nut co vi tri la k
void Node_K(NODEPTR phead, int k)
{
	NODEPTR p = phead; //int i=0;
	int i = 0;
	while (p != NULL && i<k) //while(i<n)
	{
		p = p->next; //i++;
	}
	if (p != NULL)
		printf("%4d", p->info); //printf("%4d", a[i]);
	else
		printf("\nBan nhap sai vi tri thu %d", k);
}
//Ham kiem tra danh sach rong
int IsEmpty(NODEPTR phead)
{
	return phead == NULL;
}
//Ham xoa nut dau cua danh sach lien ket
void DeleteFirst(NODEPTR &phead)
{
	if (phead==NULL)
		printf("\nDanh sach rong");
	else
	{  
		NODEPTR p = phead;
		phead = phead->next;
		delete p;
	}
}
//Ham xoa nut sau nut trong ds
void DeleteAfter(NODEPTR p)
{
	NODEPTR q;
	if (p == NULL || p->next == NULL)
		printf("\nKhong xoa duoc");
	else
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
//Ham xoa nut co vi tri z
void Delete_Z(NODEPTR &phead, int z)
{
	if (phead->info == z)
		DeleteFirst(phead);
	else
	{
		NODEPTR p = phead;
		while (p->next!= NULL)
		{
			if (p->next->info == z)
			{
				DeleteAfter(p);
				break;
			}
			p = p->next;	
		}
	}
}
//Ham sap xep
void Swap(int &x, int &y)
{
	int t = x; x = y; y = t;
}
//ham sap xep ds lk
void InterChangeSort(NODEPTR phead)
{
	for (NODEPTR p=phead; p->next!=NULL; p=p->next) //i < n - 1; i++)
	{
		for(NODEPTR q=p->next; q!=NULL; q=q->next) //for (int j = i + 1; j < n;j++)
		{
			if (p->info > q->info)
				Swap(p->info, q->info);
		}
	}
}
//Ham tim nut co gia tri lon nhat
int MaxValue(NODEPTR phead)
{
	int max = phead->info;
	NODEPTR p = phead->next; //int i=1;
	while (p != NULL) //while(i<n)
	{
		if (p->info > max)
			max = p->info;
		p = p->next; //i++;
	}
	return max;
}
//Ham tim nut co gia tri nho nhat
int MinValue(NODEPTR phead)
{
	int min = phead->info;
	NODEPTR p = phead->next; //int i=1;
	while (p != NULL) //while(i<n)
	{
		if (p->info < min)
			min = p->info;
		p = p->next; //i++;
	}
	return min;
}
//ham chinh
int main()
{
	NODEPTR phead;
	//Cau 1
	Init(phead);
	//Cau 2
	InputList(phead);
	printf("\nDanh sach sau khi nhap: ");
	//Cau 3
	ShowList2(phead);
	//Cau 4
	int x, y;
	printf("\nMoi nhap gia tri can tim x: ");
	scanf("%d", &x);
	printf("\nMoi nhap gia tri can them y: ");
	scanf("%d", &y);
	Insert_Y_After_X(phead, x, y);
	printf("\nDanh sach sau khi chen: \n");
	ShowList2(phead);
	//cau 5
	int dem = Count(phead);	
	printf("\nSo nut: %d\n", dem);
	//cau 6
	int k;
	printf("\nMoi nhap vi tri node thu k: ");
	scanf("%d", &k);
	printf("\nNut co vi tri thu %d la: ",k);
	Node_K(phead, k);
	//Cau 7
	int z;
	printf("\nMoi nhap gia tri can xoa z: ");
	scanf("%d", &z);
	Delete_Z(phead, z);
	printf("\nDanh sach sau khi xoa: \n");
	ShowList2(phead);
	//Cau 8
	InterChangeSort(phead);
	printf("\nDanh sach sau khi sap: \n");
	ShowList2(phead);
	//Cau 9
	printf("\nNut co gia tri lon nhat la: %d\n",MaxValue(phead));
	//Cau 10
	printf("\nNut co gia tri nho nhat la: %d\n",MinValue(phead));	
}

