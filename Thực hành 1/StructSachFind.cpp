#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
struct SACH
{
	int maSach;
	char tenSach[40];
	double gia;
}; //ket thuc khai bao phai co cham phay
void Nhap(SACH &s)
{
	fflush(stdin);
	printf("\nMoi nhap ma sach: ");
	scanf("%d", &s.maSach);
	printf("\nMoi nhap ten sach: ");
	gets(s.tenSach);
	gets(s.tenSach);
	printf("\nMoi nhap gia: ");
	scanf("%lf", &s.gia);
}
void Xuat(SACH s)
{
	printf("\nMa sach: %d\n", s.maSach);
	printf("\nTen sach: %s\n", s.tenSach);
	printf("\nGia: %lf\n", s.gia);
}
void Nhap(int &n)
{
	do
	{
		printf("\nMoi nhap (n>0) n: ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Ban nhap sai, moi nhap lai...");
	} while (n <= 0);
}
void NhapMang(SACH a[], int n)
{
	for (int i = 0; i < n; i++)//duy?t m?ng
	{
		printf("\nNhap thong tin sach thu %d: \n", i+1);
		Nhap(a[i]);
	}
}
void XuatMang(SACH a[], int n)
{
	for (int i = 0; i < n; i++)//duy?t m?ng
	{
		printf("\nThong tin sach thu %d: \n", i + 1);
		Xuat(a[i]);
	}
}
int Search(SACH a[], int n, int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i].maSach==x)
			return 1;
	}
	return -1;
}
void XuatSachTenY(SACH a[], int n, char ten[])
{
	for (int i = 0; i < n; i++)
	{
		if( strcmp(a[i].tenSach , ten ) == 0 )
			Xuat(a[i]);
	}
}
double TimMax(SACH a[], int n)
{
	double max = a[0].gia;
	for (int i = 1; i < n; i++)
	{
		if (a[i].gia > max)
			max = a[i].gia;
	}
	return max;
}
void XuatSachGiaMax(SACH a[], int n)
{
	double max = TimMax(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i].gia == max)
			Xuat(a[i]);
	}	
}
int main()
{
	int n,x;
	Nhap(n);
	SACH a[MAX];
	NhapMang(a,n);
	printf("\nDanh sach cac cuon sach");
	XuatMang(a,n);
	printf("\nMoi nhap ma sach can tim x: "); 
	scanf("%d",&x);
	int vt=Search(a, n, x);
	if (vt == -1)
		printf("\nTim khong thay %d", x);
	else
		printf("\nTim thay %d tai vi tri %d", x, vt);
	char ten[40];
	printf("\nMoi nhap ten sach: "); 
	scanf("\n%s",&ten);
	printf("\nCac sach co ten %s:",ten);
	XuatSachTenY(a, n, ten);
	printf("\nCac sach co gia max: ");
	XuatSachGiaMax(a,n);	
}
