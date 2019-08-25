// Pham Ngoc Vinh - 1611060042
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct benhnhan {
	char ten[50];
	int tuoi;
	int stt;
} BN;

typedef struct node {
	BN info;
	struct node *next;
} Node;

typedef struct queue {
	Node *pHead;
	Node *pEnd;
} Queue;

void KhoiTao(Queue &q) {
	q.pHead = q.pEnd = NULL;
}

Node *TaoNut(BN x) {
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void ThemSau(Queue &q, BN x) {
	Node *p = TaoNut(x);
	if (q.pEnd == NULL) q.pEnd = q.pHead = p;
	else {
		q.pEnd->next = p;
		q.pEnd = p;
	}
}

int LayDau(Queue &q, BN &x) {
	if (q.pEnd == NULL) return 0;
	Node *p = q.pHead;
	x = p->info;
	
	if (q.pEnd == q.pHead) KhoiTao(q);
	else q.pHead = p->next;
	
	delete p;
	return 1;
}

void Nhap1BN(BN &x) {
	printf("Ten benh nhan = ");
	fflush(stdin);
	gets(x.ten);
	do {
		printf("Tuoi benh nhan = ");
		scanf("%d", &x.tuoi);
		if (x.tuoi <= 0) printf("NHAP SAI! So tuoi phai > 0. Vui long nhap lai.\n");
	} while (x.tuoi <= 0);
}

void Xuat1BN(BN x) {
	printf("STT: %d\nHo ten: %s\nTuoi: %d", x.stt, x.ten, x.tuoi);
}

int DemNut(Queue q) {
	int nut = 0;
	if (q.pEnd == NULL) return nut;
	for (Node *p = q.pHead; p!=NULL; p = p->next) nut++;
	return nut;
}

int HoiCoKham() {
	int c;
	printf("\nBenh nhan nay co kham hay khong?\n(1 la co, con lai la khong)\nLua chon = ");
	scanf("%d", &c);
	if (c == 1) return 1;
	return 0;
}

void NhapBenhNhan(Queue &q, int STT) {
	BN x;
	printf("\nMOI NHAP THONG TIN BENH NHAN\n");
	Nhap1BN(x);
	x.stt = STT;
	ThemSau(q, x);
}

int main() {
	Queue q;
	KhoiTao(q);
	int STT = 0, KHAM = 0; // danh so thu tu va so nguoi kham
	
	int c;
	do {
		printf("\n\n------------------ CHUONG TRINH QL KHAM BENH ------------------------\n\n");
		printf("\t+ Nhap 1: Nhap du lieu benh nhan moi\n");
		printf("\t+ Nhap 2: Xuat benh nhan kham tiep theo\n");
		printf("\t+ Nhap 3: Xem so benh nhan CHUA duoc kham\n");
		printf("\t+ Nhap 4: Xem so benh nhan DA duoc kham\n");
		printf("\n\n---------------------------------------------------------------------\n\n");
		printf("- Lua chon cua ban: ");
		scanf("%d", &c);
		system("cls");
		switch (c) {
			case 1:
				STT++;
				NhapBenhNhan(q, STT);
				printf("\n---------------------------------------------------------------------\n");
				printf("\nSO THU TU CUA BENH NHAN: %d\n", STT);
				printf("\n---------------------------------------------------------------------\n");
				break;
			case 2:
				BN x;
				if (LayDau(q,x)) {
					printf("\nTHONG TIN BENH NHAN TIEP THEO\n\n");
					Xuat1BN(x);
					printf("\n");
					if (HoiCoKham()) KHAM++;
				} else {
					printf("\nDANH SACH RONG\nKhong con benh nhan nao tiep theo.\n\n");
				}
				break;
			case 3: 
				printf("\nSO BENH NHAN CHUA KHAM = %d\n\n", DemNut(q));
				break;
			case 4: 
				printf("\nSO BENH NHAN DA KHAM = %d\n\n", KHAM);
				break;
				break;
		}
		if (c < 1 || c > 4) break;
		system("pause");
		system("cls");
	} while (1);
	
}
