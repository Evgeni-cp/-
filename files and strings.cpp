#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//char* Reverse(char * dest, const char* source)
//{
//	int len = 0;
//	while (source[len]!='\0')
//		len++;
//	len--;
//	int j = 0;
//	for (; len >= 0; j++, len--)
//	{
//		dest[j] = source[len];
//	}
//	dest[j] = '\0';
//	return dest;
//}
//
//#define SIZE 100
//
//int main()
//{
//	char str1[SIZE] = { 0 };
//	char str2[SIZE] = { 0 };
//
//	puts("Enter a string:");
//	scanf("%s", str1);
//	Reverse(str2, str1);
//	puts(str2);
//	return 0;
//}

void WriteLowCase(FILE * fin, FILE *fout)
{
	char c = 0;
	while ((c = fgetc(fin)) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
			c += ('a' - 'A');
		else if (c >= 'a' && c <= 'z')
			c -= ('a' - 'A');
		fputc(c, fout);
	}
}

#define SIZE 1000

void WriteLowCaseInString(FILE * fin, FILE * fout)
{
	char str[SIZE] = { 0 };
	while (!feof(fin))
	{
		fgets(str, SIZE, fin);
		for (int i = 0; str[i]; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += ('a' - 'A');
			else if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= ('a' - 'A');
		}
		fputs(str, fout);
	}
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		puts("Wrong format");
		return -1;
	}
	FILE * fin = NULL, *fout = NULL;
	fin = fopen(argv[1], "r");
	if (!fin)
	{
		puts("Can't open file for reading");
		return -2;
	}
	fout = fopen(argv[2], "w");
	if (!fout)
	{
		puts("Can't open file for writing");
		return -3;
	}
	//WriteLowCase(fin, fout);
	WriteLowCaseInString(fin, fout);
	fclose(fin);
	fclose(fout);
	return 0;
}