#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void Nhap(int &n)
{
	do
	{
		printf("\nMoi nhap (n>0) n= ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Ban nhap sai, moi nhap lai...");
	} while (n <= 0);
}
void PhatSinh(int a[], int n)
{
	for (int i = 0; i < n; i++)//duy?t m?ng
		a[i] = rand() % 101 ; //phát sinh 1 s? nguyên t? 0 d?n 100
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)//duy?t m?ng
		printf("%4d", a[i]);
}
void Swap(int &x, int &y)
{
	int t = x; x = y; y = t;
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtmin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[vtmin])
				vtmin = j;
		}
		Swap(a[i], a[vtmin]);
	}
}
void InsertionSort(int a[], int n)
{
	int pos, x;
	for (int i = 1; i < n; i++)	
	{	
		pos = i - 1; x = a[i];
		while (pos >= 0 && a[pos] > x)
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				Swap(a[j], a[j - 1]);
		}
	}
}
void InterChangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j <n; j++)
		{
			if (a[j] < a[i])
				Swap(a[j], a[i]);
		}
	}
}
void QuickSort(int a[], int left, int right)
{
	int i = left, j = right, x = a[(left + right) / 2];
	do	
	{
		while (a[i] < x)i++;
		while (a[j] > x)j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i<j);
	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}
void CopyMang(int a[], int n, int b[])
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
int Menu()
{
	printf("\n\t\t***MENU***");
	printf("\n1: Sinh mang");
	printf("\n2: Xuat mang");
	printf("\n3: InterChangeSort");
	printf("\n4: BubbleSort");
	printf("\n5: SelectionSort");	
	printf("\n6: InsertionSort");
	printf("\n7: QuickSort");
	printf("\n8: Thoat");
	printf("\nMoi ban chon chuc nang: ");
	int chon;
	scanf("%d", &chon);
	return chon;
}
int main()
{
	srand( (unsigned)time(NULL) );
	int n; Nhap(n);
	int a[MAX],b[MAX];
	int chon;
	do
	{ 
		chon = Menu();
		switch (chon)
		{
			case 1: PhatSinh(b, n);
				CopyMang(b, n, a);
				break;
			case 2: XuatMang(b, n);
					break;
			case 3: InterChangeSort(a, n);
					printf("\nMang sau khi sap: ");
					XuatMang(a, n);
					break;
			case 4: BubbleSort(a, n);
					printf("\nMang sau khi sap: ");
					XuatMang(a, n);
					break;
			case 5: SelectionSort(a, n);
					printf("\nMang sau khi sap: ");
					XuatMang(a, n);
					break;
			case 6: InsertionSort(a, n);
					printf("\nMang sau khi sap: ");
					XuatMang(a, n);
					break;
			case 7: QuickSort(a, 0, n - 1);
					printf("\nMang sau khi sap: ");
					XuatMang(a, n);
					break;
			case 8: chon = 0;
					break;
			default:
					printf("\nBan chon sai...");
					break;
		}
		CopyMang(b, n, a);
	} while (chon != 0);
	printf("\n");
}
