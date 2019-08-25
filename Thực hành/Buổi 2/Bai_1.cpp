#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 300

void SinhMang(int a[], int &n) {
	printf("Nhap so luong phan tu mang can sinh = ");
	do {
		scanf("%d", &n);
		if (n >= MAX || n <= 0) printf("Nhap sai! 0 < n < %d.\nVui long nhap lai = \n",MAX);
		else break;
	} while (1);
	
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand()%101;
	}
}

void XuatMang(int a[], int n) {
	printf("\nDANH SACH MANG\n");
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i]);
	}
}
int SoSanh(int a, int b) {
	if (a>b) return 1;
	else if (a < b) return -1;
	return 0;
}

void Swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;	
}

void Selection_Sort(int a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (SoSanh(a[min], a[j]) > 0) min = j;
		}
		if (min != i) Swap(a[min], a[i]);
	}
}

void Interchange_Sort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (SoSanh(a[i], a[j]) > 0) Swap(a[i], a[j]);
		}
	}
}

void Bubble_Sort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = n-1; j > i; j--) {
			if (SoSanh(a[j-1], a[j]) > 0) Swap(a[j-1], a[j]);
		}
	}
}

void Quick_Sort(int a[], int left, int right) {
	int i = left;
	int j = right;
	int mid = a[(i+j)/2];
	do {
		while (SoSanh(a[i],mid) < 0) i++;
		while (SoSanh(a[j],mid) > 0) j--;
		if (i <= j) {
			Swap(a[i], a[j]);
			i++;
			j--;
		} else break;
	} while(1);
	if (j > left) Quick_Sort(a, left, j);
	if (i < right) Quick_Sort(a, i, right);
}

void Insertion_Sort(int a[], int n) {
	int pos, x;
	for (int i = 1; i < n; i++) {
		pos = i-1;
		x = a[i];
		while (pos >= 0 && SoSanh(a[pos], x) > 0) {
			Swap(a[pos], a[pos+1]);
			pos--;
		}
		a[pos++] = x;
	}	
}


int KiemTra(int a[], int &n) {
	if (n <= 0) {
		int c;
		printf("\nBAN CHUA SINH MANG, BAN CO MUON NHAP MANG?\n(1: DONG Y, 0: TU CHOI)\nLua chon cua ban: ");
		scanf("%d", &c);
		if (c == 1) {
			SinhMang(a, n);
			return 1;
		}
		return 0;
	}
	return 1;
}

int main() {
	int a[MAX];
	int n = 0;

	
	int c;
	do {
		printf("\n\n------------------ CHUONG TRINH NHAP MANG ---------------------------\n\n");
		printf("\t+ Nhap 1: Sinh du lieu cho mang\n");
		printf("\t+ Nhap 2: Xuat mang ra mang hinh\n");
		printf("\t+ Nhap 3: Sap xep Bubble Sort\n");
		printf("\t+ Nhap 4: Sap xep Interchange Sort\n");
		printf("\t+ Nhap 5: Sap xep Selection Sort\n");
		printf("\t+ Nhap 6: Sap xep Insertion Sort\n");
		printf("\t+ Nhap 7: Sap xep Quick Sort\n");
		printf("\n\n---------------------------------------------------------------------\n\n");
		printf("- Lua chon cua ban: ");
		scanf("%d", &c);
		system("cls");
		switch (c) {
			case 1:
				SinhMang(a,n);
				XuatMang(a,n);
				break;
			case 2:
				if (KiemTra(a, n)) XuatMang(a,n);
				break;
			case 3: 
				if (KiemTra(a, n)) {
					Bubble_Sort(a, n);
					XuatMang(a, n);
				}
				break;
			case 4: 
				if (KiemTra(a, n)) {
					Interchange_Sort(a, n);
					XuatMang(a, n);
				}
				break;
			case 5: 
				if (KiemTra(a, n)) {
					Selection_Sort(a, n);
					XuatMang(a, n);
				}
				break;
			case 6: 
				if (KiemTra(a, n)) {
					Insertion_Sort(a, n);
					XuatMang(a, n);
				}
				break;
			case 7: 
				if (KiemTra(a, n)) {
					Quick_Sort(a, 0, n-1);
					XuatMang(a, n);
				}
				break;
		}
		if (c < 1 || c > 7) break;
		system("pause");
		system("cls");
	} while (1);
	
}
