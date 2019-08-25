#include <stdio.h>
#include <conio.h>

typedef struct node
{
	int info;
	struct node * next;
}Node;

void Init(Node * &pHead);
int IsEmpty(Node* pHead);
Node* CreateNode(int X);
void InsertFirst(Node* &pHead, int x);
void InsertAfter(Node* &p, int x);
void DeleteFirst(Node* &pHead);
void DeleteAfter(Node* &p);
void DeleteAll(Node* &pHead);
void ShowList(Node* pHead);
void ShowNode(Node* p);
Node* Search(Node* pHead, int x);
Node* SearchNext(Node* pHead, int x);
void Sort(Node* &pHead) ;
void Swap(int &a, int &b);

void main()
{
	clrscr();

	Node* pHead;
	int data;
	
	printf("\n>> KHOI TAO DANH SACH\n");
	Init (pHead);
	getch();

	printf("\n>> NHAP DANH SACH\n");
	do
	{
		printf("\n Nhap du lieu (hay nhap -1 de ngung)");
		scanf("%d", &data);

		if (data != -1)
		{
			InsertFirst(pHead, data);
		}
	} while (data != -1);
	getch();

	printf("\n>> IN DANH SACH\n");
	ShowList(pHead);
	getch();

	/*
	printf("\n>> TIM KIEM TREN DANH SACH\n");
	do
	{
		printf("\n Nhap du lieu (hay nhap -1 de ngung)");
		scanf("%d", &data);
		if (data != -1)
		{
			Node* p = Search(pHead, data);
			ShowNode(p);
		}
	} while (data != -1);
	getch();

	printf("\n>> SAP XEP DANH SACH\n");
	Sort(pHead);
	getch();

	printf("\n>> IN DANH SACH DA SAP XEP\n");
	ShowList(pHead);
	getch();
	*/

	printf("\n>> XOA PHAN TU TREN DANH SACH\n");
	do
	{
		printf("\n Nhap du lieu (hay nhap -1 de ngung)");
		scanf("%d", &data);
		if (data != -1)
		{
			Node* p = SearchNext(pHead, data);
			DeleteAfter(p);
		}
	} while (data != -1);
	getch();

	printf("\n>> IN DANH SACH DA XOA\n");
	ShowList(pHead);
	getch();
}

void Init(Node * &pHead)
{
	pHead = NULL;
}

int IsEmpty(Node* pHead)
{
	return (pHead==NULL)? 1: 0;
}

Node* CreateNode(int X)
{
	Node* node=new Node;
	node->info=X;
	node->next=NULL;
	return node;
}

void InsertFirst(Node* &pHead, int x)
{
	Node* node;
	node = CreateNode(x);
	node->next = pHead;
	pHead = node;
}

void InsertAfter(Node* &p, int x)
{
	Node* node;
	if (p == NULL)
		printf("Cannot insert new node!");
	else
	{
		node = CreateNode(x);
		node->next = p->next;
		p->next = node;
	}
}

void DeleteFirst(Node* &pHead)
{
	Node* p;
	if (IsEmpty(pHead))
		printf("List is empty!");
	else 
	{
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
}

void DeleteAfter(Node* &p)
{
	Node* q;
	if (p->next ==NULL)
		printf("Cannot delete node!");
	else
	{
		q = p->next;	
		p->next = q->next;
		delete q;
	}
}

void DeleteAll(Node* &pHead)
{
	Node* p;
	while (pHead!=NULL)
	{
		p = pHead;
		pHead = p->next;
		delete p;
	}
}

void ShowList(Node* pHead)
{ 
	Node* p;
	p = pHead;
	while (p!=NULL)
	{
		ShowNode(p);
		p = p->next;
	}
}

void ShowNode(Node* p)
{
	if (p != NULL)
	{
		printf("\nData = %d", p->info);
	}
	else
		printf("Empty!");

	return;	
}

Node* Search(Node* pHead, int x)
{
	Node* p;
	p = pHead;
	while ( (p != NULL) && (p->info != x))
		p = p->next;

	return p;
}

Node* SearchNext(Node* pHead, int x)
{
	Node* p;
	p = pHead;
	while (p != NULL)
	{
		if (p->next!= NULL)
		{
			if ((p->next)->info == x)
				break;
		}
		p = p->next;
	}

	return p;
}

void Sort(Node* &pHead) 
{
	Node* q, *min, *p = pHead;
	while (p!=NULL) 
	{
		min = p; 
		q = p;
		while (q!=NULL) 
		{
			if (q->info < min->info)
			min = q;
			q = q->next;		
		}
		Swap(p->info, min->info);
		p = p->next;
	}
}

void Swap(int &a, int &b)
{
	int	 c;
	c = a;
	a = b;
	b = c;
}