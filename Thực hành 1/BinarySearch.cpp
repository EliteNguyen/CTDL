#include<stdio.h>
#define MAX 100
//Function to input the number of array
void InputN(int &n)
{
	do
	{
		printf("\nPlease enter a number of array that you want:");
		scanf("\n%d",&n);
		if(n<=0 || n>100)
			printf("\nYou've entered wrong, please! enter again:");
	}while(n<=0 || n>100);
}
//Function to iput values for array
void ArrayInput(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nPlease enter a[%d]:",i);
		scanf("\n%d",&a[i]);
	}
}
//Function to output the arrays that you've entered
void ArrayOutput(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("\n%d",a[i]);
}
//Function to input a key
void InputKey(int &x)
{
	printf("\nPlease! enter your key that you want:");
	scanf("\n%d",&x);
}
//Function Binary search
int BinarySearch(int a[], int n, int x)
{ 
	int left = 0,right = n - 1,mid;
	while (left <= right) 
	{
		mid = (left + right) / 2;
		if (x == a[mid]) 
			return mid;
		else if (x < a[mid]) 
			right = mid - 1;
		else if (x > a[mid]) 
			left = mid + 1;
	} 
	return -1;
}
//Main Function
int main()
{
	int a[MAX],n,x;
	InputN(n);
	ArrayInput(a,n);
	printf("\nThe array you've entered is:");
	ArrayOutput(a,n);
	InputKey(x);
	printf("\nThe position has a key is:%d",BinarySearch(a,n,x));
	printf("\n");		
}
