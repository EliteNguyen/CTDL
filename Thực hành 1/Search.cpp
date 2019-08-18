#include<stdio.h>
#define MAX 100
//Function to input the number of array
void InPutN(int &n)
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
//Function for search
int Search(int a[],int n,int x)
{
	InputKey(x);
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
			return i;
	}
	return -1;
}
//Main function
int main()
{
	int a[MAX],n,x;
	InPutN(n);
	ArrayInput(a,n);
	printf("\nThe array you've entered is:");
	ArrayOutput(a,n);
	int m=Search(a,n,x);
	if(m!=-1)
		printf("\nThe position has a key which you wanna find is:%d",m);
	else
		printf("\nOpps! we can not find that key :(");	
}
