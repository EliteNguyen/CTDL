#include <stdio.h>
#include <conio.h>

#define MAX 20
#define MAXDIGIT 10

void Nhap(int a[], int n);
void Xuat(int a[], int n);
	
void SelectionSort(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void ShellSort(int a[], int n, int h[], int k);
void QuickSort(int a[], int left, int right);
void RadixSort(int a[], int n);

void main()
{
	int a[100];
	int n, c;

	clrscr();

	printf("Nhap n=");
	scanf("%d", &n);

	Nhap(a, n);
	
	printf("Chon kieu sap xep: \n ");
	printf("1.SelectionSort:  \n");
	printf("2.BubbleSort:  \n");
	printf("3.InsertionSort:  \n");
	printf("4.ShellSort:  \n");
	printf("5.QuickSort:  \n");
	printf("6.RadixSort:  \n");
	printf(">>Chon kieu sap xep: ");
	scanf("%d", &c);

	switch  (c)
	{
		case 1: 
			SelectionSort(a, n);
			break;
		case 2:
			BubbleSort(a, n);
			break;
		case 3:
			InsertionSort(a, n);
			break;
		case 4:
			int h[3] = {4,2,3};
			ShellSort(a, n, h, 3);
			break;
		case 5:
			QuickSort(a, 0, n-1);
			break;
		case 6:
			RadixSort(a, n);
			break;
	}	
	
	Xuat(a, n);

	getch();

}

void Nhap(int a[], int n)
{
	for (int i=0; i < n; i++)
	{
		printf("\n >> Nhap a[%d]=", i);
		scanf("%d", &a[i]);
	}
}

void Xuat(int a[], int n)
{
	for (int i=0; i < n; i++)
	{
		printf("\na[%d] = %d", i, a[i]);
	}
}

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void SelectionSort(int a[], int n)
{
	int min;
	for(int i = 0; i < n-1; i++)
	{
		min = i;
		for(int j = i+1; j < n; j++)
			if (a[j] < a[min])
				min = j;
			Swap(a[min], a[i]);
	}
}

void BubbleSort(int a[], int n)
{
	int i, j;
	for(i =0; i < n-1; i++)
	{
		for(j=n-1; j >i; j--) 
		{
			if (a[j] < a[j-1])
				Swap(a[j], a[j-1]);
		}
	}
}

void InsertionSort(int a[], int n)
{
	int pos, x;

	for(int i=1; i < n; i++)
	{
		x = a[i]; 
		pos = i-1; 
		while ((pos >= 0) && (a[pos] > x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}

void ShellSort(int a[], int n, int h[], int k)
{
	int step, i, pos, x, len;

	for(step = 0; step < k; step++) 
	{
		len = h[step];
		for(i = len; i < n; i++) 
		{ 
			x = a[i];
			pos = i - len;
			while ((x < a[pos]) && (pos >= 0))
			{
				a[pos+len] = a[pos]; 
				pos = pos - len;
			}
			a[pos+len] = x;
		}
	}
}

void QuickSort(int a[], int left, int right) 
{
	int i, j, x;
	x = a[(left+right)/2]; 
	i = left;
	j = right;
	do {
		while (a[i] < x) i++; 
		while (a[j] > x) j--; 
		if ( i <= j) 
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i<j);
	if (left < j)
		QuickSort(a, left, j);
	if (right > i)
		QuickSort(a, i, right);
}

void RadixSort(int a[], int n)
{
	int i, j, d, digit, num;
	int h = 10;
	int B[10][MAX];
	int Len[10];
	for(d = 0; d < MAXDIGIT; d++) 
	{
		for( i = 0; i < 10; i++)
			Len[i] = 0;
		for(i = 0; i < n; i++) 
		{ 
			digit = (a[i] % h) / (h / 10);
			B[digit][Len[digit]++] = a[i];
		}
		num = 0;
		for(i = 0; i < 10; i++)
			for(j =0; j < Len[i]; j++)
				a[num++] = B[i][j];
		
		h *= 10;
	}
}
