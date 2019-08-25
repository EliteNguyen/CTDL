#include <stdio.h>

typedef struct node {
	int info;
	struct node *next;
} Node;

void KhoiTao(Node* &pHead, Node* &pEnd) {
	pHead = NULL;
	pEnd = NULL;
}

Node* TaoNut(int x) {
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void ThemDau(Node* &pHead, Node* &pEnd, int x) {
	Node *p = TaoNut(x); // tao 1 nut x
	if (pHead == NULL) pEnd = p;
	p->next = pHead;
	pHead = p;
}

void ThemCuoi(Node* &pHead, Node* &pEnd, int x) {
	Node *p = TaoNut(x);
	if (pEnd == NULL) pHead = p;
	else pEnd->next = p;
	pEnd = p;
}
void ThemDSPhanTu(Node* &pHead, Node* &pEnd) {
	int n, x;
	printf("Moi ban nhap so phan tu can them = "); 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("Moi ban phan phan tu %d = ", i);
		scanf("%d", &x);
		ThemCuoi(pHead, pEnd, x);
	}
}

void XuatDSPhanTu(Node* pHead) {
	printf("\nDANH SACH PHAN TU\n");
	for (Node *p = pHead; p!= NULL; p = p->next) printf("%4d", p->info);
}

int main() {
	Node *pHead, *pEnd;
	KhoiTao(pHead, pEnd);
	ThemDSPhanTu(pHead, pEnd);
	XuatDSPhanTu(pHead);
	return 1;
}
