#include <stdio.h>
#include <conio.h>

typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
} Node;

void Init(Node* &r);
Node* CreateNode(int x);
int InsertLeft(Node* &r, int x);
int InsertRight(Node* &r, int x);
void CreateTree(Node* &r);
void PreOrder(Node* r);
void InOrder(Node* r);
void PostOrder(Node* r);
void Search_InOrder(Node* r, int x);
Node* Search_PreOrder(Node* r, int x);
int Count_Leaf(Node* r);
int Count_Node(Node* r);
int Count_High(Node* r);
void Search_Max(Node* r, int &x);
void Sum_Node(Node* r, int &x);
void Count_If(Node* r, int x, int &n);

void main()
{
	Node *pRoot;
	
	clrscr();
	
	printf("\nKhoi tao cay");
	Init(pRoot);

	printf("\nNhap cay");
	CreateTree(pRoot);

	printf("\nIn cay: Pre-Order");
	PreOrder(pRoot);

	printf("\nIn cay: In-Order");
	InOrder(pRoot);

	printf("\nIn cay: Post-Order");
	PostOrder(pRoot);

	int n = Count_Node(pRoot);
	printf("\nSo nut = %d", n);

	n = Count_Leaf(pRoot);
	printf("\nSo nut la' = %d", n);

	n = Count_High(pRoot);
	printf("\nChieu cao = %d", n);

	n = 0;
	Search_Max(pRoot, n);
	printf("\nGia tri lon nhat = %d", n);

	n = 0;
	Sum_Node(pRoot, n);
	printf("\nTong gia tri = %d", n);
	
	n = 0;
	Count_If(pRoot, 3, n);
	printf("\nTong so nut = %d", n);
	
	getch();
}

void Init(Node* &r)
{
	r = NULL;
}

Node* CreateNode(int x)
{
	Node* n = new Node;
	n->info = x;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

int InsertLeft(Node* &r, int x)
{
	if (r == NULL)
		return 1;	//Loi
	if (r->left != NULL)
		return 1;	//Loi
	
	Node* n = CreateNode(x);
	r->left = n;

	return 0;	//Thanh cong
}

int InsertRight(Node* &r, int x)
{
	if (r == NULL)
		return 1;	//Loi
	if (r->right != NULL)
		return 1;	//Loi
	
	Node* n = CreateNode(x);
	r->right = n;

	return 0;	//Thanh cong
}

void CreateTree(Node* &r)
{
	int x;
	printf("Nhap nut goc:");
	scanf("%d", &x);
	r = CreateNode(x);
	
	printf("Nhap con trai? [Y=1/N=0]");	
	scanf("%d", &x);
	if (x == 1)
		CreateTree(r->left);
	
	printf("Nhap con phai? [Y=1/N=0]");	
	scanf("%d", &x);
	if (x == 1)
		CreateTree(r->right);
}

void PreOrder(Node* r)
{
	if (r == NULL)
		return;
	
	printf("%d", r->info);
	PreOrder(r->left);
	PreOrder(r->right);	
}

void InOrder(Node* r)
{
	if (r == NULL)
		return;
	
	InOrder(r->left);
	printf("%d", r->info);
	InOrder(r->right);	
}

void PostOrder(Node* r)
{
	if (r == NULL)
		return;
	
	PostOrder(r->left);
	PostOrder(r->right);	
	printf("%d", r->info);
}

void Search_InOrder(Node* r, int x)
{
	if (r == NULL)
		return;
	
	Search_InOrder(r->left, x);
	if (r->info == x)
		printf("%d", r->info);	
	Search_InOrder(r->right, x);	
}

Node* Search_PreOrder(Node* r, int x)
{
	if (r == NULL)
		return NULL;

	Node* p;
	
	if (r->info == x)
		return r;

	p = Search_PreOrder(r->left, x);

	if (p == NULL)
		Search_PreOrder(r->right, x);

	return p;
}

int Count_Leaf(Node* r)
{
	if (r == NULL)
		return 0;
	
	int n = 0;
	if ((r->left == NULL)&&(r->right == NULL))
		n = 1;

	n += Count_Leaf(r->left)+Count_Leaf(r->right);
	
	return n;
}

int Count_Node(Node* r)
{
	if (r == NULL)
		return 0;
	
	int n = 0;
	if (r != NULL)
		n = 1;

	n += Count_Node(r->left)+Count_Node(r->right);
	
	return n;
}

int Count_High(Node* r)
{
	if (r == NULL)
		return 0;
	else if ((r->left == NULL)&&(r->right == NULL))
		return 0;	

	int h_left = Count_High(r->left);
	int h_right = Count_High(r->right);

	return (1 + ( (h_left > h_right) ? h_left : h_right ) );
}

void Search_Max(Node* r, int &x)
{
	if (r == NULL)
		return;
	
	if (r->info > x)
		x = r->info;	
		
	Search_Max(r->left, x);
	Search_Max(r->right, x);	
}

void Count_If(Node* r, int x, int &n)
{
	if (r == NULL)
		return;
	
	if (r->info == x)
		n++;	
		
	Count_If(r->left, x, n);
	Count_If(r->right, x, n);	
}

void Sum_Node(Node* r, int &x)
{
	if (r == NULL)
		return;	
	
	x += r->info;	
		
	Sum_Node(r->left, x);
	Sum_Node(r->right, x);	
}