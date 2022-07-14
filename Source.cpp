
#include <iostream>
#include "SinglyLinkedList.h"
//Тестовый пример
int main()
{
	//Создаем объект класса List
	List<char> lst;
	List<char> lst2;
	{
		//Тестовая строка
		char s[] = "Hello, World !!!";
		//Выводим строку
		cout << s << "\n\n";
		//Определяем длину строки
		size_t len = strlen(s);
		//Загоняем строку в список
		for (size_t i = 0; i < len; i++)
			lst.Push(s[i]);
	}
	{
		//Тестовая строка
		char s[] = "Oh No, Cringe!";
		//Выводим строку
		cout << s << "\n\n";
		//Определяем длину строки
		size_t len = strlen(s);
		//Загоняем строку в список
		for (size_t i = 0; i < len; i++)
			lst2.Push(s[i]);
	}


	(lst + lst2).Print();
	(lst * lst2).Print();

	//Распечатываем содержимое списка
	lst.Print();
	//Удаляем три элемента списка
	lst.Pop();
	lst.Pop();
	lst.Pop();
	//Распечатываем содержимое списка
	lst.Print();

	return 0;
}