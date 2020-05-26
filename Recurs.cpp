#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void PrintDigits(int number)
//{
//	if (number / 10 == 0)
//	{
//		printf("%d\n", number % 10);
//		return;
//	}
//	else
//	{
//		printf("%d\n", number % 10);
//		PrintDigits(number / 10);
//	}
//}
//
//int main()
//{
//	int number = 0;
//	puts("Enter number: ");
//	scanf("%d", &number);
//	PrintDigits(number);
//	return 0;
//}


int FindMax(int * arr, int n)
{
	if (n == 1)
		return arr[0];
	int res = FindMax(arr+1, n - 1);
	return res > arr[0] ? res : arr[0];
}

void PrintArray(int*arr, int n)
{
	if (n == 0)
	{
		printf("\n");
		return;
	}		
	printf("%d\t", arr[0]);
	PrintArray(arr + 1, n - 1);
}

void InitArray(int* arr, int n)
{
	if (n == 0)
		return;
	arr[0] = rand() % 11 - 5;
	InitArray(arr + 1, n - 1);
}

int main()
{
	srand(time(0));
	int *arr1 = NULL, *arr2 = NULL;
	printf("Enter 2 unsigned: ");
	unsigned int n = 0, m = 0;
	scanf("%u%u", &n, &m);
	arr1 = (int*)malloc(n * sizeof(int));
	arr2 = (int*)malloc(m * sizeof(int));
	InitArray(arr1, n);
	PrintArray(arr1, n);
	printf("Max in first array is %d\n",
		FindMax(arr1, n));
	InitArray(arr2, m);
	PrintArray(arr2, m);
	printf("Max in second array is %d\n",
		FindMax(arr2, m));
	free(arr1);
	free(arr2);
}