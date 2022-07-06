#include <iostream>
#include <string.h>

using namespace std;

//Конкатенирует пропущенные места
void Paste(char* arr1)
{
	char arr3[256];

	strcpy_s(arr3, arr1);
	strcpy_s(arr1, 256, "");

	char* start = arr3;
	for (int i = 0; i < strlen(arr3); i++)
	{
		if (arr3[i] != (char)1 && i == 0)
		{
			start = arr3 - 1;
		}
		else if (arr3[i] == (char)1 && i + 1 != strlen(arr3))
		{
			strncat_s(arr1, 256 ,start + 1, arr3 + i - 1 - start);
			start = arr3 + i;
		}
		else if (i + 1 == strlen(arr3))
		{
			strncat_s(arr1, 256,start + 1, arr3 + i - start);
		}
	}

	if (arr1[strlen(arr1) - 1] == (char)1)
	{
		strncpy_s(arr1, 256, arr1, strlen(arr1) - 1);
	}
}

//Ставит последний символ на первое место
void Swap(char* arr1, int findex, int lindex)
{
	char* line = arr1 + findex;
	int n;
	if ((n = lindex - findex + 1) > 1) {
		char a = line[n - 1];
		memmove(line + 1, line, n - 1);
		line[0] = a;
	}
}

//Находит повторяющиеся элементы и заменяет их на пробел
void Delete(char* array, int startIndex, int endIndex)
{
	for (int i = startIndex; i <= endIndex; i++)
	{
		if (array[i] != (char)1)
		{
			for (int j = i + 1; j <= endIndex; j++)
			{
				if (array[j] == array[i])
				{
					array[j] = (char)1;
				}
			}
		}
	}
}

//Основная функция
void Replace(char* arr)
{
	int fl_end = 1, fsymb; //Объявление и инициализация переменной флага конца слова и индекса первого символа слова
	for (int i = 0; i < strlen(arr); i++)
	{
		if ((arr[i] != ' ' && arr[i] != ',') && fl_end)
		{
			fsymb = i;
			fl_end = 0;
		}
		else if (((arr[i + 1] == ' ' || arr[i + 1] == ',') || i + 1 == strlen(arr)) && !fl_end)
		{
			Swap(arr, fsymb, i);
			Delete(arr, fsymb, i);
			fl_end = 1;
		}
	}
}

int main()
{	
	char arr1[256];
	gets_s(arr1);
	Replace(arr1);
	Paste(arr1);
	puts(arr1);
}