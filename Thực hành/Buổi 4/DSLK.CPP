#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Sinhvien
{
	char ma[11];
	char hoten[41];
	float dtb;
}sv;
struct node
{
	sv info;
	struct node*next;
};
void khoitao(node*&phead)
{
	phead=NULL;


}
node*taonut(sv x)
{
	node*sv=new node;
	sv->info=x;
	sv->next=NULL;
	return sv;

}
void themdau(node*&phead,sv x)
{
	node*sv=taonut(x);
	if(phead==NULL)
		phead=sv;
	else
	{
		sv->next=phead;
		phead=sv;
	}

}
void themcuoi(node*&phead, sv x)
{
	node*sv=taonut(x);
	if(phead==NULL)
		phead=sv;
	else
	{
		for(node*t=phead;t->next!=NULL;t->next);
			t->next=sv;
	}


}
void n1sv(sv &t)
{       float tam;
	fflush(stdin);
	printf("\nNhap ma so sinh vien:"); gets(t.ma);
	fflush(stdin);
	printf("\nNhap ho va ten sinh vien:");  gets(t.hoten);
	printf("\nNhap diem trung binh:");
	scanf("%g",&tam);
	t.dtb=tam;
}
void x1sv(sv t)
{
	printf("\nmssv: %s\t hoten: %s\t dtb: %g\n",t.ma,t.hoten,t.dtb);
}
void nhapds(node*&phead)
{
	int n;
	printf("\nNhap so luong phan tu: "); scanf("%d",&n);
	for(int i=0;i<n;i++)
	{       sv x;
		 printf("\nNhap sinh vien thu: %d",i);
		 n1sv(x);
		 themdau(phead,x);
	}

}

void xds(node*phead)
{
	node*p=phead;
       if(phead==NULL)
		printf("Rong");
       while(p!=NULL)
       {     x1sv(p->info);
		p=p->next;
       }
}
void xdtb(node*phead)
{
       node*p=phead;
       while(p!=NULL)
       {
	    if(p->info.dtb>5)
		x1sv(p->info);
	     p=p->next;

       }
}
void tim(node*phead,sv &x)
{
	node*p=phead;
	printf("\nNhap ma sinh vien can tim:");
	scanf("%s",&x.ma);
	while(p!=NULL)
	{
		if(strcmp(p->info.ma,x.ma)==0)
			x1sv(p->info);
			p=p->next;
	}
}
node*tim2(node*phead,sv &x)
{
	printf("\nNhap ten sinh vien can tim:");
	scanf("%s",&x.hoten);
	for(node*p=phead;p!=NULL;p=p->next)
	{
		if(strcmp(p->info.hoten,x.hoten)==0)
			return p;

	}  return NULL;


}
void themsau2(node*p,sv x)
{
	if(p==NULL)
		printf("KO THAY");
	else
	{
		node*tam=taonut(x);
		tam->next=p->next;
		p->next=tam;
	}


}
void swap(sv &x, sv &y)
{

	sv tam=x;
	x=y;
	y=tam;
}
void xeptang(node*phead)
{
	for(node*i=phead;i->next!=NULL;i=i->next)
	{
		node*vtmin=i;
		for(node*j=i->next;j->next!=NULL;j=j->next)
		{
			if(j->info.dtb<vtmin->info.dtb)
			{	vtmin=j;
				swap(vtmin->info,i->info);
			 }
		}


	}  	xds(phead);
}
void tim3(node*phead,sv &x)
{
	node*p=phead;
	printf("\nNhap ten sinh vien can tim:");
	scanf("%s",&x.hoten);
	while(p!=NULL)
	{
		if(strcmp(p->info.hoten,x.hoten)==0)
			x1sv(p->info);
			p=p->next;
	}
}
void deletefirst(node*&phead)
{
	node*p;
	if (phead==NULL)
	printf("\nDanh sach rong!");
	else
	{
		p=phead;
		phead=phead->next;
		delete p;
	}
}
void deletelast(node*&phead)
{
	node*t=phead;
	node*p=t->next;
	while(p->next!=NULL)
		{
			t=p;
			p=p->next;
		}
		t->next=NULL;
		delete p;
}
void clearlist(node*&phead)
{
	node*p;
	while(phead!=NULL)
	{
		p=phead;
		phead=p->next;
		delete p;
	}
}
void deleteafter(node*p)
{
	node*q;
	if(p==NULL||p->next==NULL)
	printf("cannot delete node!");
	else
	{
		q=p->next;
		p->next=q->next;
		delete q;
	}
}
void deleteSV(node*&phead,sv x)
{
	printf("\nNhap vao ten sv can xoa: ");
	scanf("%s", &x.hoten);
	if(phead==NULL) printf("\ndanh sach rong!");
	else
	{
		if(strcmp(phead->info.hoten,x.hoten)==0)
		deletefirst(phead);
		else
			{
				node*t=phead;node*p=t->next;
				while(strcmp(p->info.hoten,x.hoten)!=0)
				{

					t=p;
					p=p->next;
				}
				t->next=p->next;
				delete p;
			}
	}
}



void xuathskha(node*&phead)
{
	node*p=phead;
	while(p!=NULL)
	{
		if((p->info.dtb)>6.5 && (p->info.dtb)<8.5)
		{
		x1sv(p->info);
		p=p->next;
		}
		else
			printf("\nKhong co hs kha!");
			 break;

	 }
}






int main()
{       sv x;
	char t;
	sv y;
	clrscr();
	node*phead;
	node*sv;
	khoitao(phead);
	nhapds(phead);
	printf("\nDSSV:");
	xds(phead);
	printf("\nSinh vien co dtb >5:");
	xdtb(phead);
	printf("\nSinh vien kha: ");
	xuathskha(phead);
	tim(phead,x);
	/*printf("\nsap xep : ");
	xeptang(phead); */
	deletefirst(phead);
	printf("\nXoa dau: ");
	xds(phead);
	printf("\nXoa cuoi: ");
	deletelast(phead);
	xds(phead);
	deleteSV(phead,x);
	xds(phead);



       /*	node*kq=tim2(phead,x);
	if(kq==NULL)
		printf("KO thay\n");
	else
	{
		n1sv(y);
		printf("DS sau khi them\n");
		themsau2(kq,y);
		xds(phead);

	}
	tim3(phead,x);*/
	getch();
	return 0;

}
