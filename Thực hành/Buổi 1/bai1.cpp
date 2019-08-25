#include "stdio.h"
#include "stdlib.h"
#define MAX 100

void NhapN(int &n) {
	do {
		printf("Moi nhap n > 0: ");
		scanf("%d", &n);
		if (n > 0 && n < MAX) break;
		printf("Nhap sai, 0 < n < %d\n", MAX);
	} while (1);
}

void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("- Nhap a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int a[], int n) {
	printf("\n------------ DANH SACH MANG -------------\n");
	for (int i = 0; i < n; i++) {
		printf("- a[%d] = %d\n", i, a[i]);
	}
	printf("\n-----------------------------------------\n");
}

int TimKiem_TuyenTinh(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) return i;
	}
	return -1;
}

void SapXep(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int TimKiem_NhiPhan(int a[], int n, int x) {
	int m, l = 0, r = n-1;
	while (l <= r) {
		m = (l+r)/2;
		if (a[m] == x) return m;
		else if (a[m] < x) l = m+1;
		else r = m-1;
	}
	return -1;
}

void NhapLieu(int a[], int &n) {
	printf("\n-------------- NHAP MANG --------------------\n");
	NhapN(n);
	NhapMang(a, n);
}

int KiemTra(int a[], int &n) {
	if (n == 0) {
		int c;
		printf("\nBAN CHUA NHAP MANG, BAN CO MUON NHAP MANG?\n(1: DONG Y, 0: TU CHOI)\nLua chon cua ban: ");
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

int KiemTraSapXep(int a[], int n) {
	int flag = 1;
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1]) {
			flag = -1;
			break;
		}
	}
	if (flag < 0) {
		int c;
		printf("\nBAN CHUA SAP XEP MANG, BAN CO MUON SAP XEP MANG?\n(1: DONG Y, 0: TU CHOI)\nLua chon cua ban: ");
		scanf("%d", &c);
		if (c == 1) {
			SapXep(a, n);
			system("cls");
			return true;
		}
		return false;
	}
	return true;
}

int main() {
	int a[MAX];
	int n = 0;
	
	int c;
	do {
		printf("\n\n------------------ CHUONG TRINH NHAP MANG ---------------------------\n\n");
		printf("\t+ Nhap 1: Nhap du lieu cho mang\n");
		printf("\t+ Nhap 2: Xuat mang ra mang hinh\n");
		printf("\t+ Nhap 3: Sap xep lai mang tang dan\n");
		printf("\t+ Nhap 4: Tim kiem tuyen tinh\n");
		printf("\t+ Nhap 5: Tim kiem tuan tu\n");
		printf("\n\n---------------------------------------------------------------------\n\n");
		printf("- Lua chon cua ban: ");
		scanf("%d", &c);
		system("cls");
		switch (c) {
			case 1:
				NhapLieu(a, n);
				break;
			case 2:
				if (KiemTra(a, n)) XuatMang(a, n);
				break;
			case 3: 
				if (KiemTra(a, n)) {
					SapXep(a, n);
					XuatMang(a, n);
				}
				break;
			case 4:
				if (KiemTra(a, n)) {
					int x;
					printf("\nCHUC NANG TIM KIEM\nMoi nhap x = ");
					scanf("%d", &x);
					
					int p = TimKiem_TuyenTinh(a, n, x);
					printf("\n---------------------------------------------------------------------");
					if (p >= 0) printf("\n- Tim kiem duoc a[%d] = %d\n", p, x);
					else printf("\n- Khong tim thay phan tu co gia tri bang %d\n", x);
					printf("---------------------------------------------------------------------\n");
				}
				break;
			case 5:
				if (KiemTra(a, n) && KiemTraSapXep(a, n)) {
					int x, p;
					printf("\nCHUC NANG TIM KIEM\nMoi nhap x = ");
					scanf("%d", &x);
					p = TimKiem_NhiPhan(a, n, x);
					printf("\n---------------------------------------------------------------------");
					if (p >= 0) printf("\n- Tim kiem duoc a[%d] = %d\n", p, x);
					else printf("\n- Khong tim thay phan tu co gia tri bang %d\n", x);	
					printf("---------------------------------------------------------------------\n");	
				}
				break;
		}
		if (c < 1 || c > 5) break;
		system("pause");
		system("cls");
	} while (1);
	
	return 0;
}
