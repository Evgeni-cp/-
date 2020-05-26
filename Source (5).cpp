#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 5

int main()
{
	long **arr = NULL;
	long* sum = NULL;
	srand(time(0));
	arr = (long**)malloc(ROW * sizeof(long*));
	sum = (long*)malloc(COL * sizeof(long));
	for (int i = 0; i < ROW; i++)
	{
		arr[i] = (long*)malloc(COL * sizeof(long));
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % 11 - 5;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < COL; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < ROW; j++)
		{
			sum[i] += arr[j][i];
		}
		printf("Sum of elements in %d line is %d\n",
			i + 1, sum[i]);
		
	}
	for (int i = 0; i < ROW; i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(sum);

}

//long** InitArray(long **ar)
//{
//	ar = (long**)malloc(ROW * sizeof(long*));
//	for (int i = 0; i < ROW; i++)
//	{
//		ar[i] = (long*)malloc(COL * sizeof(long));
//		for (int j = 0; j < COL; j++)
//		{
//			ar[i][j] = rand() % 11 - 5;
//		}
//	}
//	return ar;
//}
//
//void PrintArray(long **ar)
//{
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("%5d", ar[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int CalculateSumm(long * arr, int N)
//{
//	int sum = 0;
//	for (int j = 0; j < N; j++)
//	{
//		sum += arr[j];
//	}
//	return sum;
//}
//
//long* CalculateSumInMatrix(long **arr)
//{
//	long* sum = (long*)malloc(ROW * sizeof(long));
//	for (int i = 0; i < ROW; i++)
//	{
//		sum[i] = CalculateSumm(arr[i], COL);
//	}
//	return sum;
//}
//
//long** DeleteArray(long** arr)
//{
//	for (int i = 0; i < ROW; i++)
//	{
//		free(arr[i]);
//	}
//	free(arr);
//	return NULL;
//}
//
//void PrintLineArray(long* arr, int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}
//
//
//int main()
//{
//	long **arr =  NULL;
//	long*sum = NULL;
//	srand(time(0));
//	arr = InitArray(arr);
//	PrintArray(arr);
//	sum = CalculateSumInMatrix(arr);
//	PrintLineArray(sum, ROW);
//	arr = DeleteArray(arr);
//	free(sum);
//}
//
