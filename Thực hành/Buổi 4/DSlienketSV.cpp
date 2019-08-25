#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sinhvien
{
	char masv[10],hoten[40];
	float dtb;
}sv;
typedef struct node
{
	sv info;
	struct node* next;
}node;
void init(node *&phead) //khoi tao
{
	phead=NULL;
}
node* createnode(sv x) //tao nut
{
	node* p=new node;
	p->info=x;
	p->next=NULL;
	return p;
}
void insertfirst(node* &phead,sv x)  //them vao dau danh sach
{
	node* p=createnode(x);
	if(phead==NULL) phead=p;
	else
	{
		p->next=phead;
		phead=p;
	}

}
void input1sv(sv &x)
{
	fflush(stdin);
	printf("\nMa sinh vien: "); scanf("%s",&x.masv);
	fflush(stdin);
	printf("\nTensv:"); gets(x.hoten);
	fflush(stdin);
	float t;
	printf("\nDiem trung binh:"); scanf("%f",&t);
	x.dtb=t;
}
void inputdssv(node* &phead) //nhap danh sach sinh vien
{

	int n;
	printf("\nNhap so phan tu:");scanf("%d",&n);
	for(int i=0;i<n;i++)
	{       printf("\nNhap sinh vien thu %d",i);
		sv x;
		input1sv(x);
		insertfirst(phead,x);
	}


}
void output1sv(sv x) //Xuat 1 sinh vien
{
	printf("\nMasv: %s  Tensv: %s  DTB: %.2f",x.masv,x.hoten,x.dtb);
}

void outputdssv(node* phead)
{
	for(node* i=phead;i!=NULL;i=i->next)
	{
		output1sv(i->info);
	}
}
void outputdtbtren5(node* phead)  //Xuat cac sinh vien dtb tren 5
{
	printf("\nDanh sach cac sinh vien co diem trung binh tren 5: \n");
	for(node* i=phead;i!=NULL;i=i->next)
	{
		if(i->info.dtb>5) output1sv(i->info);
	}
}
void searchmasv(node* phead,char x[]) //tim theo masv
{
	for(node* i=phead;i!=NULL;i=i->next)
	{
		if(strcmp(i->info.masv,x)==0) output1sv(i->info);
	}
}
//Ham sap xep
void sapxep(sv &i,sv &j)
{
	sv tam;
	tam=i;
	i=j;
	j=tam;
}
//sap xep danh sach tang dan
void SortDtb(node* phead)
{
	for(node* i=phead; i!=NULL; i=i->next)
	{
		for(node* j=i->next;j!=NULL;j=j->next)
		{
			if(i->info.dtb>j->info.dtb)
			{
				sapxep(i->info,j->info);
			}
		}
	}
}
node* timtensv(node* phead,char x[])
{
	for(node* i=phead;i!=NULL;i=i->next)
	{
		if(strcmp(i->info.hoten,x)==0)
		return i;
	}
	return NULL;
}
// Ham them sinh vien
void addsv(node* phead,char x[])
{       sv a;
	printf("\nNhap thong tin cua sinh vien can them:");
	input1sv(a);

	node* kq=timtensv(phead,x);
	for(node* i=phead;i!=NULL;i=i->next)
	{
		if(i==kq)
		{       node* p=createnode(a);
			p->next=i->next;
			i->next=p;
		}
	}
}
// Xoa sinh vien dung dau danh sach
void deletefirst(node* &phead)
{
       node* p=phead;
       phead=phead->next;
       delete p;
}
// xoa cuoi
void deletecuoi(node* &phead)
{
	node* p;
	node* q;
	p=q=phead;
	if(phead->next==NULL) delete phead;
	else{
	while (q->next!=NULL)
	{
		p=q;
		q=q->next;
	}
	delete(q);
	p->next=NULL;
	}
}

//xoalist
void deletelist(node* &phead)
{

	while(phead!=NULL)
	{
		node* t;
		t=phead;
		phead=phead->next;
		delete t;
	}
}
// Xoa sau
void DeleteAfter(node *p)
{
	if (p==NULL || p->next==NULL) printf("Can't delete'");
	else
	{
		node *q=p->next;
		p->next=q->next;
		delete q;
	}
}
// Xoa tat ca Sv co ten X
void DeleteName(node *&phead,char x[40])
{
	if (phead==NULL);
	else
	{
		for (node *k=phead; k!=NULL; k=k->next)
		{
		if (strcmp(phead->info.hoten,x)==0)
			deletefirst(phead);
			else
			{
				node *t=phead; node *p=t->next;
				while (strcmp(p->info.hoten,x)!=0)
				{
					t=p;
					p=p->next;
				}
				t->next=p->next; delete p;
			}
		}
	}
}
// Xoa sau ten X
void DeleteNameAfter(node *&phead,char x[40])
{
	if (phead==NULL);
	else
	{
		if (strcmp(phead->info.hoten,x)==0)
			DeleteAfter(phead);
		else
		{
			node *t=phead; node *p=t->next;
			while (strcmp(t->info.hoten,x)!=0)
			{
				t=p;
				p=p->next;
			}
			t->next=p->next; delete p;
		}
	}
}
// Sap xep theo ma
void SortMa(node* phead)
{
	for(node* i=phead; i!=NULL; i=i->next)
	{
		for(node* j=i->next; j!=NULL; j=j->next)
		{
			if(strcmp(i->info.masv,j->info.masv)>0)
			{
				sapxep(i->info,j->info);
			}
		}
	}
}
// DSSV loai kha
void TimKha(node* phead)
{
	for(node* i=phead; i!=NULL; i=i->next)
		if(i->info.dtb>6.5 && i->info.dtb<8) output1sv(i->info);
}
// DTB Max,min
void Max(node *phead)
{
	node *Max=phead;
	for (node* i=phead; i->next!=NULL; i=i->next)
		if (i->info.dtb < i->next->info.dtb) Max=i->next;
	for (node* j=phead; j!=NULL; j=j->next)
		if (j->info.dtb==Max->info.dtb)	output1sv(j->info);
}
/*void DSGioi(node *&phead)
{
	if (phead==NULL);
	else
	{
		for (node *k=phead; k!=NULL; k=k->next)
		{
			if (phead->info.dtb<8) deletefirst(phead);
			else
			{
				node *t=phead; node *p=t->next;
				while (t->info.dtb>8)
				{
					t=p;
					p=p->next;
				}
				t->next=p->next; delete t;
			}
		}
	}
}*/
// Ham chinh
int main()
{
	node* phead;
	init(phead);
	inputdssv(phead);
	printf("\nDanh sach sinh vien sau khi sap xep tang theo dtb: "); SortDtb(phead); outputdssv(phead);
//	printf("\nDanh sach sinh vien sau khi sap xep tang theo ma: "); SortMa(phead);
//	printf("\nDanh sach sinh vien xep loai kha: "); TimKha(phead);
//	printf("\nDanh sach sinh vien dtb cao nhat: "); Max(phead);
//	printf("\nDanh sach sinh vien Gioi co dtb thap nhat: "); MinGioi(phead);
//	outputdtbtren5(phead);
//	char macantim[10];
	char x[40];
//	printf("\nNhap masv can tim:");scanf("%s", &macantim); searchmasv(phead,macantim);
//	fflush(stdin); char tencantim[40];
//	printf("\nNhap ten sinh vien de them 1 sinh vien sau sinh vien do:"); gets(tencantim);
//	printf("\nThong tin cua sinh vien ban vua tim:\n");	output1sv(timtensv(phead,tencantim)->info); addsv(phead,tencantim);	outputdssv(phead); deletefirst(phead);
//	printf("\nDanh sach sinh vien sau khi xoa dau:"); outputdssv(phead); deletecuoi(phead);
//	printf("\nDanh sach sinh vien sau khi xoa cuoi:"); outputdssv(phead); deletelist(phead);
//	printf("\nDanh sach sinh vien sau khi xoa tat ca:"); outputdssv(phead);
//	fflush(stdin); printf("\nNhap ten SV can xoa: "); gets(x); DeleteName(phead,x);
//	fflush(stdin); printf("\nNhap ten SV can xoa sau: "); gets(x); DeleteNameAfter(phead,x);
//	outputdssv(phead);
	printf("\nDanh sach SV gioi: "); DSGioi(phead); outputdssv(phead);
	getch();
}
