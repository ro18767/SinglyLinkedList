#include "SinglyLinkedList.h"

using namespace std;

int main()
{
	SinglyLinkedList sll;

	// вставка в конец списка
	sll.AddToTail(10);
	sll.AddToTail(20);
	sll.AddToTail(30);
	sll.AddToTail(40);
	sll.Print();

	// вставка в начало списка
	sll.AddToHead(50);
	sll.AddToHead(60);
	sll.AddToHead(70);
	sll.AddToHead(80);
	sll.Print();

	// количество элементов, поиск элементов
	cout << "count: " << sll.GetCount() << "\n";
	cout << "index of 70: " << sll.IndexOf(70) << ", index of 90: " << sll.IndexOf(90) << "\n";

	// вставка по позиции
	sll.InsertInto(-1, -1);
	sll.Print();
	sll.InsertInto(2, 2);
	sll.Print();
	sll.InsertInto(22, 22);
	sll.Print();

	// удаление с начала списка
	sll.DeleteFromHead();
	sll.DeleteFromHead();
	sll.DeleteFromHead();
	sll.Print();

	// удаление с конца списка
	sll.DeleteFromTail();
	sll.DeleteFromTail();
	sll.DeleteFromTail();
	sll.Print();

	// удаление по указанному индексу
	sll.DeleteByIndex(0);
	sll.DeleteByIndex(1);
	sll.DeleteByIndex(2);
	sll.Print();

	// очистка списка
	sll.Clear();
	sll.Print();
}