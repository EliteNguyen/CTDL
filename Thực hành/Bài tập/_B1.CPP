#include <stdio.h>
#include <conio.h>

void Nhap(int a[], int n);
int TimKiem1(int a[], int n, int key);
int TimKiem2(int a[], int n, int key);
int TimNhiPhan(int a[], int n, int key);

void main()
{
	int a[10];
	int x = 6;
	int n, kq1, kq2;

	clrscr();

	printf("Nhap n=");
	scanf("%d", &n);

	Nhap(a, n);
	//kq1 = TimKiem1(a, n, x);
	//kq2 = TimKiem2(a, n, x);
	//printf("Kq1=%d, Kq2=%d", kq1, kq2);

	kq1 = TimNhiPhan(a, n, x);
	printf("Kq1=%d", kq1);

	getch();

}

void Nhap(int a[], int n)
{


	for (int i=0; i < n; i++)
	{
		printf("Nhap a[%d]", i);
		scanf("%d", &a[i]);
	}
}

int TimKiem1(int a[], int n, int key)
{
	int i = 0;

	while (i < n && a[i] != key)
		i++;

	if (i < n)
		return i;	//tim thay
	return -1;		//tim khong thay
}

int TimKiem2(int a[], int n, int key)
{
	int i = 0;

	a[n] = key;

	while (a[i] != key)
		i++;

	if (i == n)
		return -1;	//tim khong thay

	return i;		//tim thay
}

int TimNhiPhan(int a[], int n, int key)
{
	int left = 0;
	int right = n-1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (a[mid] == key)
			return mid;
		else if (a[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}