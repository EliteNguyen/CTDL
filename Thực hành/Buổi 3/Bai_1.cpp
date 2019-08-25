#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
	int info;
	struct node* next;
} Node;



// Tao nut
Node* TaoNut(int x) {
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

// Them dau
void ThemDau(Node *&pHead, Node *&pEnd, int x) {
	Node *p = TaoNut(x);
	if (pHead == NULL) pEnd = p;
	p->next = pHead;
	pHead = p;
}

// Them cuoi
void ThemCuoi(Node *&pHead, Node *&pEnd, int x) {
	if (pHead == NULL) {
		ThemDau(pHead, pEnd, x);
	} else {
		Node *p = TaoNut(x);
		pEnd->next = p;
		pEnd = p;
	}
}

// Xuat Node
void XuatDaySo(Node* pHead) {
	system("cls");
	printf("\n---------------------- DAY SO NGUYEN ------------------------\n");
	
	int i = 0;
	for (Node *p = pHead; p!=NULL; p = p->next) {
		i++;
		printf("%5d", p->info);
		if (i > 9) {
			i = 0;
			printf("\n");
		}
	}
	printf("\n-------------------------------------------------------------\n");
}

// Nhap Node
void NhapDaySo(Node *&pHead, Node *&pEnd) {
	system("cls");
	int n, x;
	do {
		printf("\n----------------- NHAP DAY SO NGUYEN ------------------------\n");
		printf("Moi nhap so luong phan tu muon them = ");
		scanf("%d", &n);
		if (n > 0) break;
		printf("LOI! Vui long nhap lai, so luong phan tu phai lon hon 0\n");
		system("pause");
		system("cls");
	} while (1);
	printf("-------------------------------------------------------------\n");
	
	for (int i = 0; i < n; i++) {
		printf("- Moi ban nhap phan tu thu %d = ", i+1);
		scanf("%d", &x);
		ThemCuoi(pHead, pEnd, x);
	}
}

// Tu sinh Node
void SinhMang(Node *&pHead, Node *&pEnd) {
	system("cls");
	int n, x;
	do {
		printf("\nRANDOM DAY SO NGUYEN BAT KI\n");
		printf("Moi nhap so luong phan tu muon random = ");
		scanf("%d", &n);
		if (n > 0) break;
		printf("LOI! Vui long nhap lai, so luong phan tu phai lon hon 0\n");
		system("pause");
		system("cls");
	} while (1);
	
	int f, t;
	
	do {
		printf("\n\nMIEN DU LIEU RANDOM");
		printf("\nRandom tu a = ");
		scanf("%d", &f);
		printf("Den b = ");
		scanf("%d", &t);
		if (f < t) break;
		printf("\n\nLOI!! Mien du lieu khong hop le, dieu kien a < b\n\n");
		system("pause");
		system("cls");
	} while (1);
	
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		x = rand()%(t-f+1) + f;
		ThemCuoi(pHead, pEnd, x);
	}
	
	XuatDaySo(pHead);
}


// Xoa Node
void XoaNode(Node *&pHead, Node *&pEnd, Node *Xoa) {
	if (pHead == NULL) return;
	
	Node *truoc = NULL;
	for (Node *p = pHead; p->next != NULL; p = p->next) {
		if (p->next == Xoa) truoc = p;
	}
	if (truoc != NULL) truoc->next = Xoa->next;
	
	if (pEnd == Xoa) pEnd = truoc;
	if (pHead == Xoa) pHead = Xoa->next;
	
	delete Xoa;
}

// Xoa toan bo Node
void XoaToanBoNode(Node *&pHead, Node *&pEnd) {
	if (pHead == NULL) return;
	
	Node *t;
	for (Node *p = pHead; p !=NULL; p = t) {
		t = p->next;
		delete p;
	}

	pHead = NULL;
	pEnd = NULL;
}

// Ham ho tro nhap lieu
int NhapLieu(Node* &pHead, Node* &pEnd) {
	system("cls");
	int c;
	if (pHead != NULL) {
		printf("LUA CHON PHUONG THUC NHAP\nDay so da ton tai, ban muon nhap moi hay nhap tiep?\n(1: nhap tiep, 2: nhap moi, 0: huy thao tac)\n\nLua chon cua ban: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				NhapDaySo(pHead, pEnd);
				return 1;
			case 2:
				XoaToanBoNode(pHead, pEnd);
				return NhapLieu(pHead, pEnd);
			default:
				return 0;
		}
	} else {
		printf("LUA CHON PHUONG THUC NHAP\n(1: tu nhap, 2: random du lieu, 0: huy thao tac)\n\nLua chon cua ban: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				NhapDaySo(pHead, pEnd);
				return 1;
			case 2:
				SinhMang(pHead, pEnd);
				return 1;
			default:
				return 0;
		}
	}
}
// Kiem tra mang
int KiemTraDaySo(Node* &pHead, Node* &pEnd) {
	system("cls");
	if (pHead == NULL) {
		printf("CANH BAO!!!\nBan chua nhap day so nao, ban co muon nhap lieu ko?\n(1: dong y, 0: huy thao tac)\n\nLua chon cua ban: ");
		int c;
		scanf("%d", &c);
		switch (c) {
			case 1:
				if (NhapLieu(pHead, pEnd)) {
					system("cls");
					return 1;	
				}
			default:
				return 0;
		}
	}
	return 1;
}

// Tim phan tu co gia tri x
Node* TimX(Node *pHead, int x) {
	for (Node *p = pHead; p!= NULL; p = p->next) {
		if (p->info == x) return p;
	}
	return NULL;
}

// Them phan tu x sau nut p co gia tri la y
int ThemSauX(Node *&pHead, Node *&pEnd, int x, int y) {
	Node *t = TimX(pHead, y);
	if (t == NULL) return 0;
	
	Node *p = TaoNut(x);
	p->next = t->next;
	t->next = p;
	
	if (pEnd == t) pEnd = p;
	
	return 1;
}

// Xoa node X
void XoaNodeX(Node *&pHead, Node *&pEnd, int x, int c = 0) {
	if (pHead == NULL) return;
	do {
		Node *t = TimX(pHead, x);
		if (t != NULL) XoaNode(pHead, pEnd, t);
		else break;
		if (c == 0) break;
	} while (1);
}

// Sap xep tang dan Interchange Sort
void Interchange_Sort(Node *pHead) {
	for (Node *i = pHead; i->next != NULL; i = i->next) {
		for (Node *j=i->next; j != NULL; j = j->next) {
			if (i->info > j->info) {
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}
	
}

// Sap xep giam dan Selection Sort
void Selection_Sort(Node *pHead) {
	Node *max = NULL;
	
	for (Node *i = pHead; i->next != NULL; i = i->next) {
		max = i;
		for (Node *j=i->next; j != NULL; j = j->next) {
			if (j->info > max->info) max = j;
		}
		if (i != max) {
			int temp = i->info;
			i->info = max->info;
			max->info = temp;
		}
	}
}

// Kiem tra tang dan / giam dan
int KiemTraThuTu(Node *pHead, Node *pEnd) {
	int tang_dan = 1;
	int giam_dan = 1;
	
	for (Node *p = pHead; p->next != NULL; p = p->next) {
		if (p->info > (p->next)->info) tang_dan = 0;
		else if (p->info < (p->next)->info) giam_dan = 0;
	}
	
	if (pHead->info == pEnd->info) {
		tang_dan = 0;
		giam_dan = 0;
	}
	
	if (tang_dan == 1) return 1;
	if (giam_dan == 1) return 2;
	return 0;
}

// Kiem tra phan tu chan va le co xen ke nhau ko
int KiemTraChanLe(Node *pHead, Node *pEnd) {
	if (pHead == pEnd) return 0;
	
	for (Node *p = pHead; p->next != NULL; p = p->next) {
		if (p->info%2 + (p->next)->info%2 != 1) return 0;
	}

	return 1;
}

int main() {
	// pHead va pEnd
	Node *pHead = NULL, *pEnd = NULL;
	
	int c;
	do {
		printf("\n\n------------------ CHUONG TRINH NHAP MANG ---------------------------\n\n");
		printf("\t+ Nhap 1: Nhap du lieu cho mang\n");
		printf("\t+ Nhap 2: Xuat mang ra mang hinh\n");
		printf("\t+ Nhap 3: Them phan tu sau mot phan tu khac\n");
		printf("\t+ Nhap 4: Xoa phan tu co gia tri bat ky\n");
		printf("\t+ Nhap 5: Sap xep danh sach\n");
		printf("\n\n---------------------------------------------------------------------\n\n");
		printf("- Lua chon cua ban: ");
		scanf("%d", &c);
		system("cls");
		switch (c) {
			case 1:
				NhapLieu(pHead, pEnd);
				break;
			case 2:
				if (KiemTraDaySo(pHead, pEnd)) {
					XuatDaySo(pHead);
					int kq = KiemTraThuTu(pHead, pEnd);
					if (kq == 1) printf("\nKIEM TRA THU TU: DAY LA DAY TANG DAN\n");
					else if (kq == 2) printf("\nKIEM TRA THU TU: DAY LA DAY GIAM DAN\n");
					
					kq = KiemTraChanLe(pHead, pEnd);
					if (kq) printf("\nKIEM TRA CHAN LE: CAC PHAN TU CHAN LE NAM XEN KE NHAU\n");
					else printf("\nKIEM TRA CHAN LE: CAC PHAN TU CHAN LE KHONG NAM XEN KE NHAU\n");
					
				}
				
				break;
			case 3: 
				if (KiemTraDaySo(pHead, pEnd)) {
					int x, y;
					printf("\nTHEM PHAN TU X SAU PHAN TU Y\nMoi ban nhap x can them = ");
					scanf("%d", &x);
					printf("Moi ban nhap phan tu y = ");
					scanf("%d", &y);
					system("cls");
					if (ThemSauX(pHead, pEnd, x, y)) {
						XuatDaySo(pHead);
					} else {
						printf("LOI!!! KHONG TIM THAY PHAN TU CO GIA TRI %d NEN KHONG THE THEM VAO\n", y);
					}
				}
				
				break;
			case 4:
				if (KiemTraDaySo(pHead, pEnd)) {
					int ch;
					printf("LUA CHON PHUONG THUC XOA\n(0: xoa 1 phan tu dau tien tim duoc, 1: xoa toan bo)\n\nLua chon cua ban: ");
					scanf("%d", &ch);
					if (ch != 1) ch = 0;
					system("cls");
					int x;
					printf("XOA PHAN TU X\nMoi ban nhap gia tri x can xoa = ");
					scanf("%d", &x);
					XoaNodeX(pHead, pEnd, x, ch);
					system("cls");
					XuatDaySo(pHead);
				}
				break;
			case 5:
				if (KiemTraDaySo(pHead, pEnd)) {
					int ch;
					printf("LUA CHON PHUONG THUC SAP XEP\n(1: Interchange Sort - Tang dan, 2: Selection Sort - giam dan)\n\nLua chon cua ban: ");
					scanf("%d", &ch);
					system("cls");
					if (ch == 1) {
						Interchange_Sort(pHead);
					} else {
						Selection_Sort(pHead);
					}
					XuatDaySo(pHead);
				}
				break;
		}
		if (c < 1 || c > 5) break;
		printf("\n\n(An phim bat ky de tiep tuc)\n");
		system("pause");
		system("cls");
	} while (1);
	
}
