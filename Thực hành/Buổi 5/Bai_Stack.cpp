// Pham Ngoc Vinh - 1611060042
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *next;
} Node;

typedef struct stack {
	Node *pHead;
	Node *pEnd;
} Stack;

void KhoiTao(Stack &s) {
	s.pHead = s.pEnd = NULL;
}

Node *TaoNut(int x) {
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void ThemSau(Stack &s, int x) {
	Node *p = TaoNut(x);
	if (s.pEnd == NULL) s.pEnd = s.pHead = p;
	else {
		s.pEnd->next = p;
		s.pEnd = p;
	}
}

int LayCuoi(Stack &s, int &x) {
	if (s.pEnd == NULL) return 0;
	Node *p = s.pEnd;
	x = p->info;
	
	if (s.pEnd == s.pHead) KhoiTao(s);
	else {
		Node *t;
		for (t = s.pHead; t->next != s.pEnd; t = t->next);
		s.pEnd = t;
		t->next = NULL;
	}
	
	delete p;
	return 1;
}

int main() {
	Stack s;
	KhoiTao(s);
	int n, x;
	
	
	do {
		printf("\nMoi ban nhap n = ");
		scanf("%d", &n);
		system("cls");
		if (n > 0) break;
		printf("\nNHAP SAI! Ban phai nhap n > 0, vui long nhap lai\n");
		system("pause");
	} while(1);
	
	// chia lay du
	int m = n;
	while (m != 0) {
		x = m%2;
		m=m/2;
		ThemSau(s, x);
	}
	
	// xuat so nhi phan
	printf("\nDOI SANG SO NHI PHAN DUNG STACK\n\n%d = ", n);
	while (LayCuoi(s, x)) {
		printf("%d", x);
	}
	
}
