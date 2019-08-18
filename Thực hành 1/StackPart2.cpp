#include<stdio.h>
#define MAXNODE 100
struct Node
{
	int info;
	struct Node* next;
};
typedef struct Node* STACK;
void Init(STACK &s)
{
	s = NULL;
}
int IsEmpty(STACK s)
{
	return (s == NULL);
}
STACK CreateNode(int x)
{
	STACK p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void Push(STACK &s, int x)
{
	STACK p = CreateNode(x);
	p->next = s;
	s = p;
}
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
void Doi(STACK &s, int n, int he)
{
	while (n > 0)
	{
		int du = n % he;
		Push(s, du);
		n = n / he;
	}
}
int Pop(STACK &s)
{
	if (!IsEmpty(s) )	//if (IsEmpty(s) ==0)  n?u không r?ng
	{
		int x = s->info;
		STACK pDel = s;
		s = s->next;
		delete pDel;
		return x;
	}
	return -1;
}
void Xuat(STACK s)
{
	while ( !IsEmpty(s) )   //while(IsEmpty(s) == 0 )
	{
		int x = Pop(s);
		if (x >= 10)
			printf("%c", x + 55);
		else
			printf("%d", x);
	}
}
int main()
{
	STACK s;
	Init(s);
	int n; Nhap(n);
	int he;
	printf("\nMoi nhap he (2,8,10,16) = "); scanf("%d", &he);
	Doi(s, n,he);
	printf("\n%d sang he %d: ", n, he);
	Xuat(s);
	printf("\n");
}

