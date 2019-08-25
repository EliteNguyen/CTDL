#include <stdio.h>
#include <conio.h>

typedef struct Node
{
	int data;
	struct Node* next;
}node;

void KhoiTao(node* &pH);

void NhapTruoc(node* &pH, int x);

void Xem(node* pH);

void Tim(node* pH, int x);

void Xoa(node* &pH, int x);

void SapXep(node* &pH);

void ChonLoc(node* &pH);

void ChonLoc2(node* &pH);

void main()
{
	node* pHead;
	int x;

	clrscr();

	KhoiTao(pHead);

	printf("\nNhap danh sach.\n");
	do
	{
		printf(">>Nhap mot gia tri (-1 de ngung)=");
		scanf("%d", &x);
		if (x!=-1)
			NhapTruoc(pHead, x);
	}while (x!=-1);

	printf("\n>>>>>> In danh sach.\n");
	Xem(pHead);

	/*
	printf("\nSap xep danh sach.\n");
	SapXep(pHead);
	Xem(pHead);

	do
	{
		printf(">>Nhap mot gia tri can tim (-1 de ngung)=");
		scanf("%d", &x);
		if (x!=-1)
			Tim(pHead, x);
	}while (x!=-1);

	do
	{
		printf(">>Nhap mot gia tri can xoa (-1 de ngung)=");
		scanf("%d", &x);
		if (x!=-1)
		{
			Xoa(pHead, x);
			Xem(pHead);
		}
	}while (x!=-1);
	*/

	printf("\n>>>>>>> Chon loc");
	ChonLoc2(pHead);
	Xem(pHead);

	getch();

}

void KhoiTao(node* &pH)
{
	pH = NULL;
}

void NhapTruoc(node* &pH, int x)
{
	//Tao nut
	node* n = new node;
	//Luu thong tin
	n->data = x;
	//Chen vao dau danh sach
	n->next = pH;
	//pH se chi vao phan tu moi them
	pH = n;
}

void Xem(node* pH)
{
	node* p = pH;
	int i = 0;
	while (p!=NULL)
	{
		printf("Nut thu %d : %d\n", i++, p->data);
		p = p->next;
	}
}

void Tim(node* pH, int x)
{
	node* p = pH;

	int i = 0;
	while ((p!=NULL)&&(p->data != x))
	{
		p = p->next;
		i++;
	}

	if (p)
		printf("\nTim thay %d o vi tri %d\n", p->data, i);
	else
		printf("\nTim khong thay\n");

	return;
}

void Xoa(node* &pH, int x)
{
	node *p, *q;
	int i;

	if (pH == NULL)
	{
		printf("Danh sach rong, khong xoa duoc %d", x);
		return;
	}
	else if (pH->data == x)	//phan tu dau trung x
	{
		q = pH;

		pH = pH->next;

		delete q;

		return;
	}
	else	//co it nhat 2 phan tu, phan tu dau khac x
	{
		p = pH;

		while (p->next != NULL)
		{
			if ((p->next)->data == x)
			{
				q = p->next;
				p->next = q->next;
				delete q;
			}
			else
				p = p->next;
		}

	}
}

void SapXep(node* &pH)
{
	node *p = pH;
	node *q;
	int tam;

	while (p)
	{
		q = p->next;
		while (q)
		{
			if (p->data < q->data)
			{
				tam = p->data;
				p->data = q->data;
				q->data = tam;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void ChonLoc(node* &pH)
{
	node *p = pH;
	node *q, *r;
	int tam;

	while (p)
	{
		q = p->next;
		while (q)
		{
			r = q->next;
			if ((r) && (p->data == r->data))
			{
				q->next = r->next;
				delete r;
			}
			/*
			else if (p->data = q->data)
			{
				r = q;
				q->next = r->next;
				delete q;
			}
			*/
			q = q->next;
		}
		p = p->next;
	}
}

void ChonLoc2(node* &pH)
{
	SapXep(pH);

	node *p = pH;
	node *q;
	int tam;


	while (p)
	{
		q = p->next;

		if (p->data == q->data)
		{
			p->next = q->next;
			delete q;
		}
		else
			p = p->next;
	}
}
