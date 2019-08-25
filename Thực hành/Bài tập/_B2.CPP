#include <stdio.h>
#include <conio.h>
#include <string.h>

struct MoTa_Sach
{
	int Ma;
	char Ten[40];
	long Gia;
};

typedef MoTa_Sach Sach;

Sach msach[100];
int n;

void NhapSoLuong();
void NhapSach();
void XuatSach();
void TimMa_InSach();
int TimMa();
void TimTen_InSach();
int TimTen();
void TimGia_InSach();
void TimGiaLonNhat_InSach();


void main()
{
	clrscr();

	NhapSoLuong();

	NhapSach();

	XuatSach();

	TimMa_InSach();

	TimTen_InSach();

	TimGia_InSach();

	TimGiaLonNhat_InSach();

	getch();
}

void NhapSoLuong()
{
	do
	{
		printf("Nhap so luong sach n=");
		scanf("%d", &n);
	}while ((n <= 0) ||(n >= 100));
}

void NhapSach()
{
	printf(">> Nhap sach\n");

	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nNhap cuon sach thu %d\n", i+1);

		printf("\tNhap ma sach=");
		scanf("%d", &(msach[i].Ma));

		printf("\tNhap ten sach=");
		scanf("%s", &(msach[i].Ten));

		printf("\tNhap gia sach=");
		scanf("%ld", &(msach[i].Gia));
	}
	printf("-----------");
}


void XuatSach()
{
	printf(">> Xuat thong tin sach\n");

	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nNoi dung cuon sach thu %d\n", i+1);

		printf("\tMa sach=%d\n", msach[i].Ma);
		printf("\tTen sach=%s\n", msach[i].Ten);
		printf("\tGia sach=%ld\n", msach[i].Gia);
	}
	printf("-----------");
}

int TimMa()
{
	int i, key, vt;

	printf(">> TimMa\n");

	printf("Nhap ma sach can tim=");
	scanf("%d", &key);

	for (i = 0, vt = -1; i < n; i++)
	{
		if (msach[i].Ma == key)
		{
			vt = i;
			break;
		}
	}

	return vt;
}

void TimMa_InSach()
{
	int i, key;

	printf(">> TimMa_InSach\n");

	printf("Nhap ma sach can tim=");
	scanf("%d", &key);

	for (i = 0; i < n; i++)
	{
		if (msach[i].Ma == key)
			break;
	}

	if (i < n)
	{
		printf("\nNoi dung cuon sach thu %d\n", i+1);

		printf("\tMa sach=%d\n", msach[i].Ma);
		printf("\tTen sach=%s\n", msach[i].Ten);
		printf("\tGia sach=%ld\n", msach[i].Gia);
	}
}

int TimTen()
{
	int i, vt;
	char key[40];

	printf(">> TimTen\n");

	printf("Nhap ten sach can tim=");
	scanf("%s", &key);

	for (i = 0, vt = -1; i < n; i++)
	{
		if (strcmp(msach[i].Ten, key) == 0)
		{
			vt = i;
			break;
		}
	}

	return vt;
}

void TimTen_InSach()
{
	int i;
	char key[40];

	printf(">> TimTen_InSach\n");

	printf("Nhap ten sach can tim=");
	scanf("%s", &key);

	for (i = 0; i < n; i++)
	{
		if (strcmp(msach[i].Ten, key) == 0)
			break;
	}

	if (i < n)
	{
		printf("\nNoi dung cuon sach thu %d\n", i+1);

		printf("\tMa sach=%d\n", msach[i].Ma);
		printf("\tTen sach=%s\n", msach[i].Ten);
		printf("\tGia sach=%ld\n", msach[i].Gia);
	}
}

void TimGia_InSach()
{
	int i;
	long key;

	printf(">> TimGia_InSach\n");

	printf("Nhap gia thap nhat can tim=");
	scanf("%ld", &key);

	for (i = 0; i < n; i++)
	{
		if (msach[i].Gia >= key)
		{
			printf("\nNoi dung cuon sach thu %d\n", i+1);

			printf("\tMa sach=%d\n", msach[i].Ma);
			printf("\tTen sach=%s\n", msach[i].Ten);
			printf("\tGia sach=%ld\n", msach[i].Gia);
		}
	}
}

void TimGiaLonNhat_InSach()
{
	int i;
	long key;

	printf(">> TimGiaLonNhat_InSach\n");

	for (i = 1, key = msach[0].Gia; i < n; i++)
	{
		if (msach[i].Gia > key)
			key = msach[i].Gia;
	}

	printf("Gia sach lon nhat=%ld\n", key);

	for (i = 0; i < n; i++)
	{
		if (msach[i].Gia != key)
			continue;

		printf("\nNoi dung cuon sach thu %d\n", i+1);

		printf("\tMa sach=%d\n", msach[i].Ma);
		printf("\tTen sach=%s\n", msach[i].Ten);
		printf("\tGia sach=%ld\n", msach[i].Gia);
	}
}

