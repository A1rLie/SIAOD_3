#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void SwapAndSave(char& buffOld, char& buffNew, char array[], int index)
{
	buffOld = buffNew; //Записываем предыдущий символ в старое хранилище
	buffNew = array[index]; //В новое хранилище записываем текущий символ
	array[index] = buffOld; //Меняем текущий символ на старый
}

//Находит повторяющиеся элементы и заменяет их на пробел
void Delete(char* array, int startIndex, int endIndex)
{
	for (int i = startIndex; i <= endIndex; i++)
	{
		if (array[i] != (char)0)
		{
			for (int j = i+1; j <= endIndex; j++)
			{
				if (array[j] == array[i])
				{
					array[j] = (char)0;
				}
			}
		}
	}
}

void Replace(char array[], int length)
{
	int fl_end = 1, first_symb; //Объявление и инициализация переменной флага конца слова и индекса первого символа слова
	char buff_old = ' ', buff_new = ' '; //Буффер для хранения удаленного символа и для хранения удаляемого символа
	for (int i = 0; i < 256; i++)
	{
		if (array[i] != ' ' && array[i] != ',' && fl_end == 1) //Если слово начинается
		{
			fl_end = 0; //Установка что это не конец слова
			first_symb = i; //Индекс первого символа, для последующей замены
		}
		if (fl_end == 0)//Если это не конец слова
		{
			if (array[i + 1] == ' ' || array[i + 1] == ',' || array[i + 1] == '\0') fl_end = 1; //Проверка на последний символ и в случае успеха установка флага конца
			if (fl_end == 0) //Если это не последний символ
			{
				SwapAndSave(buff_old, buff_new, array, i);
			}
			else //Если же это последний символ
			{
				SwapAndSave(buff_old, buff_new, array, i);
				swap(array[first_symb], buff_new); //Меняем местами первый символ и текущий символ до его замены
				Delete(array, first_symb, i);
			}
		}
	}
}


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
			strncat_s(arr1, 256, start + 1, arr3 + i - 1 - start);
			start = arr3 + i;
		}
		else if (i + 1 == strlen(arr3))
		{
			strncat_s(arr1, 256, start + 1, arr3 + i - start);
		}
	}

}

int main()
{
    char str[256];
    gets_s(str); //Ввод строки
	Replace(str, strlen(str));
	Paste(str);
	puts(str); //Вывод строки
	
  
}
