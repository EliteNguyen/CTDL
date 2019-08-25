#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAX 300

typedef struct nhanvien {
	char ma[11];
	char ten[40];
	int luong;
} NV;

void NhapN(int &n) {
	do {
		printf("Moi nhap n > 0: ");
		scanf("%d", &n);
		if (n > 0 && n < MAX) break;
		printf("Nhap sai, 0 < n < %d\n", MAX);
	} while (1);
}

void NhapNV(NV &a) {
	printf("- Moi nhap ma nhan vien: ");
	fflush(stdin);
	gets(a.ma);
	printf("- Moi nhap ten nhan vien: ");
	fflush(stdin);
	gets(a.ten);
	printf("- Moi nhap luong nhan vien: ");
	scanf("%d", &a.luong);
}

int TimKiem_TuyenTinh(NV a[], int n, char x[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].ma, x) == 0) return i;
	}
	return -1;
}

void NhapMangNV(NV a[], int n) {
	for (int i = 0; i < n; i++) {
		
		do {
			printf("\nMOI BAN NHAP THONG TIN NHAN VIEN THU %d\n", i+1);
			NhapNV(a[i]);
			if (TimKiem_TuyenTinh(a, i, a[i].ma) < 0) break;
			printf("\n---------------------------------------------------------------------------");
			printf("\nCANH BAO !!! NHAN VIEN NAY DA TON TAI, VUI LONG NHAP LAI DU LIEU NAY !!!\n") ;
			printf("---------------------------------------------------------------------------\n");
		} while (1);
		
	}
}

void XuatNV(NV a) {
	printf("%-15s| %-40s| %d\n", a.ma, a.ten, a.luong);
}

void XuatMangNV(NV a[], int n) {
	printf("%-15s| %-40s| %s\n", "MA", "TEN NV", "LUONG");
	for (int i = 0; i < n; i++) {
		XuatNV(a[i]);
	}
}

int SoSanh(char a[], char b[]) {
	return strcmp(a, b);
}

void Swap(NV &a, NV &b) {
	NV t = a;
	a = b;
	b = t;
}

void Selection_Sort(NV a[], int n, int c = 0) {
	int min, t;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (!c) t = SoSanh(a[min].ma, a[j].ma);
			else t = SoSanh(a[min].ten, a[j].ten);
			if ( t > 0) min = j;
		}
		if (min != i) Swap(a[min], a[i]);
	}
}

void Interchange_Sort(NV a[], int n, int c = 0) {
	int t;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (!c) t = SoSanh(a[i].ma, a[j].ma);
			else t = SoSanh(a[i].ten, a[j].ten);
			if (t > 0) Swap(a[i], a[j]);
		}
	}
}

void Bubble_Sort(NV a[], int n, int c = 0) {
	int t;
	for (int i = 0; i < n-1; i++) {
		for (int j = n-1; j > i; j--) {
			if (!c) t = SoSanh(a[j-1].ma, a[j].ma);
			else t = SoSanh(a[j-1].ten, a[j].ten);
			if (t > 0) Swap(a[j-1], a[j]);
		}
	}
}

void Quick_Sort(NV a[], int left, int right, int c = 0) {
	int t;
	int i = left;
	int j = right;
	NV mid = a[(i+j)/2];
	do {
		if (!c) {
			while (SoSanh(a[i].ma,mid.ma) < 0) i++;
			while (SoSanh(a[j].ma,mid.ma) > 0) j--;
		}
		else {
			while (SoSanh(a[i].ten,mid.ten) < 0) i++;
			while (SoSanh(a[j].ten,mid.ten) > 0) j--;
		}
		
			

		if (i <= j) {
			Swap(a[i], a[j]);
			i++;
			j--;
		} else break;
	} while(1);
	if (j > left) Quick_Sort(a, left, j, c);
	if (i < right) Quick_Sort(a, i, right, c);
}

void Insertion_Sort(NV a[], int n, int c = 0) {
	int t;
	int pos;
	NV x;
	for (int i = 1; i < n; i++) {
		pos = i-1;
		x = a[i];
		
		if (!c) {
			while (pos >= 0 && SoSanh(a[pos].ma, x.ma) > 0) {
				Swap(a[pos], a[pos+1]);
				pos--;
			}
		}
		else {
			while (pos >= 0 && SoSanh(a[pos].ten, x.ten) > 0) {
				Swap(a[pos], a[pos+1]);
				pos--;
			}
		}
		a[pos++] = x;
	}	
}


int Add(NV a[], int &n) {
	system("cls");
	if (n >= MAX) return false;
	printf("\nMOI BAN NHAP THONG TIN NHAN VIEN\n");
	
	do {
		NhapNV(a[n]);
		if (TimKiem_TuyenTinh(a, n, a[n].ma) < 0) break;
		printf("\n---------------------------------------------------------------------------");
		printf("\nCANH BAO !!! MA NHAN VIEN NAY DA TON TAI, VUI LONG NHAP LAI DU LIEU NAY !!!\n");
		printf("---------------------------------------------------------------------------\n");
	} while (1);
		
	
	n++;
	return true;
	system("cls");
}

void NhapLieu(NV a[], int &n) {
	if (n > 0) {
		int c;
		printf("\nHIEN DANH SACH SACH DA CO\nBAN MUON NHAP THEM HAY NHAP MOI?\n(1: NHAP THEM, 0: NHAP MOI)\nLua chon cua ban: ");
		scanf("%d", &c);
		if (c == 1) {
			if (!Add(a, n)) printf("\nDANH SACH SACH DA DAY KHONG THE NHAP THEM\n");
			else printf("\nDA THEM VAO DANH SACH THANH CONG\n");
			return;
		}
	}
	NhapN(n);
	NhapMangNV(a, n);
}

int KiemTraNhapLieu(NV a[], int &n) {
	if (n == 0) {
		int c;
		printf("\nBAN CHUA NHAP DANH SACH, BAN CO MUON NHAP KHONG?\n(1: DONG Y, 0: TU CHOI)\nLua chon cua ban: ");
		scanf("%d", &c);
		if (c == 1) {
			system("cls");
			NhapLieu(a, n);
			system("cls");
			return true;
		}
		return false;
	}
	return true;
}

int main() {
	NV a[MAX];
	int n = 0;

	
	int c;
	do {
		printf("\n\n------------------ CHUONG TRINH NHAN VIEN ---------------------------\n\n");
		printf("\t+ Nhap 1: Nhap du lieu nhan vien\n");
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
				NhapLieu(a, n);
				break;
			case 2:
				if (KiemTraNhapLieu(a, n)) XuatMangNV(a, n);
				break;
			case 3: 
				if (KiemTraNhapLieu(a, n)) {
					int cach = 0;
					printf("\nLUA CHON CACH SAP XEP?\n(1: THEO TEN, 0: THEO MA)\nLua chon cua ban: ");
					scanf("%d", &cach);
					if (cach != 1) cach = 0;
					Bubble_Sort(a, n, cach);
					XuatMangNV(a, n);
				}
				break;
			case 4: 
				if (KiemTraNhapLieu(a, n)) {
					int cach = 0;
					printf("\nLUA CHON CACH SAP XEP?\n(1: THEO TEN, 0: THEO MA)\nLua chon cua ban: ");
					scanf("%d", &cach);
					if (cach != 1) cach = 0;
					Interchange_Sort(a, n, cach);
					XuatMangNV(a, n);
				}
				break;
			case 5: 
				if (KiemTraNhapLieu(a, n)) {
					int cach = 0;
					printf("\nLUA CHON CACH SAP XEP?\n(1: THEO TEN, 0: THEO MA)\nLua chon cua ban: ");
					scanf("%d", &cach);
					if (cach != 1) cach = 0;
					Selection_Sort(a, n, cach);
					XuatMangNV(a, n);
				}
				break;
			case 6: 
				if (KiemTraNhapLieu(a, n)) {
					int cach = 0;
					printf("\nLUA CHON CACH SAP XEP?\n(1: THEO TEN, 0: THEO MA)\nLua chon cua ban: ");
					scanf("%d", &cach);
					if (cach != 1) cach = 0;
					Insertion_Sort(a, n, cach);
					XuatMangNV(a, n);
				}
				break;
			case 7: 
				if (KiemTraNhapLieu(a, n)) {
					int cach = 0;
					printf("\nLUA CHON CACH SAP XEP?\n(1: THEO TEN, 0: THEO MA)\nLua chon cua ban: ");
					scanf("%d", &cach);
					if (cach != 1) cach = 0;
					Quick_Sort(a, 0, n-1, cach);
					XuatMangNV(a, n);
				}
				break;
		}
		if (c < 1 || c > 7) break;
		system("pause");
		system("cls");
	} while (1);
	
}
