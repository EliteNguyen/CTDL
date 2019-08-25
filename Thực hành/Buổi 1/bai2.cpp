#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 100

typedef struct Sach {
	char ma[10];
	char ten[40];
	float gia;
} SACH;

int Add(SACH a[], int &n);
int TimKiem_TuyenTinh(SACH a[], int n, char x[]);

void NhapN(int &n) {
	do {
		printf("Moi nhap n > 0: ");
		scanf("%d", &n);
		if (n > 0 && n < MAX) break;
		printf("Nhap sai, 0 < n < %d\n", MAX);
	} while (1);
}

void NhapSach(SACH &a) {
	printf("- Moi nhap ma sach: ");
	fflush(stdin);
	gets(a.ma);
	printf("- Moi nhap ten sach: ");
	fflush(stdin);
	gets(a.ten);
	printf("- Moi nhap gia sach: ");
	scanf("%f", &a.gia);
}

void NhapMangSach(SACH a[], int n) {
	for (int i = 0; i < n; i++) {
		
		do {
			printf("\nMOI BAN NHAP THONG TIN SACH THU %d\n", i+1);
			NhapSach(a[i]);
			if (TimKiem_TuyenTinh(a, i, a[i].ma) < 0) break;
			printf("\n---------------------------------------------------------------------------");
			printf("\nCANH BAO !!! MA SACH NAY DA TON TAI, VUI LONG NHAP LAI DU LIEU NAY !!!\n") ;
			printf("---------------------------------------------------------------------------\n");
		} while (1);
		
	}
}

void XuatSach(SACH a) {
	printf("%-10s| %-35s| %.2f\n", a.ma, a.ten, a.gia);
}

void XuatMangSach(SACH a[], int n) {
	printf("%-10s| %-35s| %s\n", "MA", "TEN SACH", "GIA");
	for (int i = 0; i < n; i++) {
		XuatSach(a[i]);
	}
}

int TimKiem_TuyenTinh(SACH a[], int n, char x[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].ma, x) == 0) return i;
	}
	return -1;
}

void SapXep(SACH a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (strcmp(a[i].ma,a[j].ma) > 0) {
				SACH temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int TimKiem_NhiPhan(SACH a[], int n, char x[]) {
	int m, l = 0, r = n-1;
	while (l <= r) {
		m = (l+r)/2;
		if (strcmp(a[m].ma, x) == 0) return m;
		else if (strcmp(a[m].ma, x) < 0) l = m+1;
		else r = m-1;
	}
	return -1;
}

void XuatSachTheoTen(SACH a[], int n, char y[]) {
	printf("\n-------------------- KET QUA TIM KIEM ----------------------\n");
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].ten, y) == 0) {
			if (flag == 0) printf("%-10s| %-35s| %s\n", "MA", "TEN SACH", "GIA");
			flag++;
			XuatSach(a[i]);
		}
	}
	if (flag == 0) printf("\n- KHONG tim thay cuon sach nao ten %s", y);
	printf("------------------------------------------------------------\n");
}

float Max(SACH a[], int n) {
	float max = a[0].gia;
	for (int i = 1; i < n; i++) {
		if (a[i].gia > max) max = a[i].gia;
	}
	return max;
}

void XuatSachGiaMax(SACH a[], int n) {
	float max = Max(a, n);
	printf("\n-------------------- SACH GIA CAO NHAT ----------------------\n");
	printf("%-10s| %-35s| %s\n", "MA", "TEN SACH", "GIA");
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].gia == max) XuatSach(a[i]);
	}
	printf("------------------------------------------------------------\n");
}

void NhapLieu(SACH a[], int &n) {
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
	NhapMangSach(a, n);
}

int KiemTraNhapLieu(SACH a[], int &n) {
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


int KiemTraSapXep(SACH a[], int n) {
	int flag = 1;
	for (int i = 0; i < n-1; i++) {
		if (strcmp(a[i].ma, a[i+1].ma) > 0) {
			flag = -1;
			break;
		}
	}
	if (flag < 0) {
		int c;
		printf("\nBAN CHUA SAP XEP DANH SACH, BAN CO MUON SAP XEP KHONG?\n(1: DONG Y, 0: TU CHOI)\nLua chon cua ban: ");
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

void XuatDS(SACH a[], int n) {
	printf("\n----------------------- IN DANH SACH ------------------------\n");
	XuatMangSach(a, n);
	printf("--------------------------------------------------------------\n");
	
}

int Add(SACH a[], int &n) {
	system("cls");
	if (n >= 100) return false;
	printf("\nMOI BAN NHAP THONG TIN SACH\n");
	
	do {
		NhapSach(a[n]);
		if (TimKiem_TuyenTinh(a, n, a[n].ma) < 0) break;
		printf("\n---------------------------------------------------------------------------");
		printf("\nCANH BAO !!! MA SACH NAY DA TON TAI, VUI LONG NHAP LAI DU LIEU NAY !!!\n");
		printf("---------------------------------------------------------------------------\n");
	} while (1);
		
	
	n++;
	return true;
	system("cls");
}
int main() {
	char x[10];
	int n = 0, p;
	SACH a[MAX];
	
	int c;
	do {
		printf("\n\n------------------ CHUONG TRINH QUAN LY SACH -------------------------\n\n");
		printf("\t+ Nhap 1: Nhap du lieu\n");
		printf("\t+ Nhap 2: Xuat danh sach ra mang hinh\n");
		printf("\t+ Nhap 3: Sap xep lai theo ma tang dan\n");
		printf("\t+ Nhap 4: Tim kiem tuyen tinh\n");
		printf("\t+ Nhap 5: Tim kiem tuan tu\n");
		printf("\t+ Nhap 6: Tim kiem theo ten\n");
		printf("\t+ Nhap 7: In ra sach co gia dat nhat\n");
		printf("\n\n---------------------------------------------------------------------\n\n");
		printf("- Lua chon cua ban: ");
		scanf("%d", &c);
		system("cls");
		switch (c) {
			case 1:
				NhapLieu(a, n);
				break;
			case 2:
				if (KiemTraNhapLieu(a, n)) XuatMangSach(a, n);
				break;
			case 3: 
				if (KiemTraNhapLieu(a, n)) {
					SapXep(a, n);
					XuatMangSach(a, n);
				}
				break;
			case 4:
				if (KiemTraNhapLieu(a, n)) {
					printf("Nhap Ma so sach can tim = ");
					fflush(stdin);
					gets(x);
					
					int p = TimKiem_TuyenTinh(a, n, x);
					printf("\n---------------------------------------------------------------------");
					if (p >= 0) printf("\n- [TT] Tim kiem duoc ID %s - [VT: %d] %s", x, p, a[p].ten);
					else printf("\n- [TT] Khong tim thay sach co ma bang %s", x);
					printf("\n---------------------------------------------------------------------\n");	
				}
				break;
			case 5:
				if (KiemTraNhapLieu(a, n) && KiemTraSapXep(a, n)) {
					printf("Nhap Ma so sach can tim = ");
					fflush(stdin);
					gets(x);
					p = TimKiem_NhiPhan(a, n, x);
					printf("\n---------------------------------------------------------------------");
					if (p >= 0) printf("\n- [NP] Tim kiem duoc ID %s - [VT: %d] %s", x, p, a[p].ten);
					else printf("\n- [NP] Khong tim thay sach co ma bang %s", x);
					printf("\n---------------------------------------------------------------------\n");	
				}
				break;
			case 6:
				if (KiemTraNhapLieu(a, n)) {
					char y[40];
					printf("\n\nNhap ten sach can tim kiem: ");
					fflush(stdin);
					gets(y);
					XuatSachTheoTen(a, n, y);
				}
				break;
			case 7:
				if (KiemTraNhapLieu(a, n)) {
					printf("\nDANH SACH SACH CO GIA DAT NHAT\n");
					XuatSachGiaMax(a, n);
				}
				break;
		}
		if (c < 1 || c > 7) break;
		system("pause");
		system("cls");
	} while (1);
	
	return 0;
}
