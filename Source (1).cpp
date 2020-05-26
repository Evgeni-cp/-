#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 5

//int main()
//{
//	long arr[ROW][COL] = { 0 };
//	srand(time(0));
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			arr[i][j] = rand() % 11 - 5;
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < ROW; i++)
//	{
//		int sum = 0;
//		for (int j = 0; j < COL; j++)
//		{
//			sum += arr[i][j];
//		}
//		printf("Sum of elements in %d line is %d\n",
//			i + 1, sum);
//	}
//
//}

void InitArray(long ar[][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			ar[i][j] = rand() % 11 - 5;
		}
	}
}

void PrintArray(long ar[][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%5d", ar[i][j]);
		}
		printf("\n");
	}
}

int CalculateSumm(long * arr, int N)
{
	int sum = 0;
	for (int j = 0; j < N; j++)
	{
		sum += arr[j];
	}
	return sum;
}

void CalculateSumInMatrix(long arr[][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		printf("Sum of elements in %d line is %d\n",
			i + 1, CalculateSumm(arr[i], COL));
	}
}


int main()
{
	long arr[ROW][COL] = { 0 };
	srand(time(0));
	InitArray(arr);
	PrintArray(arr);
	CalculateSumInMatrix(arr);

}