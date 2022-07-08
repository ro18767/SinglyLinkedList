#include <iostream>
using namespace std;

struct Element
{
	//Данные
	char data;
	//Адрес следующего элемента списка
	Element* Next;
};
//Односвязный список
class List
{
	//Адрес головного элемента списка
	Element* Head;
	//Адрес концевого элемента списка
	Element* Tail;
	//Количество элементов списка
	size_t Count;
public:
	//Конструктор
	List();
	List(const List&);
	List(List&&) noexcept;
	List& operator=(const List&);
	List& operator=(List&&) noexcept;
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Push(char);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	char Pop();
	//Удаление всего списка
	void PopAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void Print();
	//Получение количества элементов,
	//находящихся в списке
	size_t GetCount();
	List operator+(List&);
	List operator*(List&);
};