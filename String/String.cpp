#include <iostream>
#include <string>

using namespace std;


void SwapAndSave(char& buffOld, char& buffNew, string& line, int index)
{
	buffOld = buffNew; //Записываем предыдущий символ в старое хранилище
	buffNew = line[index]; //В новое хранилище записываем текущий символ
	line[index] = buffOld; //Меняем текущий символ на старый
}

//Находит повторяющиеся элементы и удаляет их
void Delete(string& line)
{
	for (int i = 0; i < line.size(); i++)
	{
		int j = line.find(line[i], i + 1);
		while (j != -1 && j)
		{
			line.erase(j, 1);
			j = line.find(line[i], i + 1);
		}
	}
}

void Replace(string& line)
{
	int fl_end = 1, first_symb; //Объявление и инициализация переменной флага конца слова и индекса первого символа слова
	char buff_old = ' ', buff_new = ' '; //Буффер для хранения удаленного символа и для хранения удаляемого символа
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ' && line[i] != ',' && fl_end == 1) //Если слово начинается
		{
			fl_end = 0; //Установка что это не конец слова
			first_symb = i; //Индекс первого символа, для последующей замены
		}
		if (fl_end == 0)//Если это не конец слова
		{
			if (line[i + 1] == ' ' || line[i + 1] == ',' || line[i + 1] == '\0') fl_end = 1; //Проверка на последний символ и в случае успеха установка флага конца
			if (fl_end == 0) //Если это не последний символ
			{
				SwapAndSave(buff_old, buff_new, line, i);
			}
			else //Если же это последний символ
			{
				SwapAndSave(buff_old, buff_new, line, i);
				swap(line[first_symb], buff_new); //Меняем местами первый символ и текущий символ до его замены
				string newString = line.substr(first_symb, i - first_symb + 1);
				Delete(newString);
				line.replace(first_symb, i - first_symb + 1, newString);
			}
		}
	}
}


int main()
{
	string str = "Hello world";
	getline(cin, str); //Ввод строки
	Replace(str);

	cout << str; //Вывод строки
}
