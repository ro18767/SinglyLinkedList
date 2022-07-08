#include "SinglyLinkedList.h"
List::List()
{
	//Изначально список пуст
	Head = Tail = nullptr;
	Count = 0;
}
List::List(const List& _List) :List() {
	//запоминаем адрес головного элемента
	Element* temp = _List.Head;

	Element** all_data = new Element * [_List.Count];

	//Пока еще есть элементы
	int i = 0;
	while (i < _List.Count)
	{
		//сохраняем указатель на данные
		all_data[i] = temp;
		//Переходим на следующий элемент
		temp = temp->Next;
		i++;
	}
	//Пока еще есть элементы

	while (i-- > 0)
	{
		//копируем данные
		Push(all_data[i]->data);
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	delete[] all_data;

}
List::List(List&& _List) noexcept :List() {
	Head = _List.Head;
	Tail = _List.Tail;
	Count = _List.Count;
	_List.Head = nullptr;
	_List.Tail = nullptr;
	_List.Count = 0;
}
List& List::operator=(const List& _List) {
	PopAll();
	//запоминаем адрес головного элемента
	Element* temp = _List.Head;

	Element** all_data = new Element * [_List.Count];

	//Пока еще есть элементы
	int i = 0;
	while (i < _List.Count)
	{
		//сохраняем указатель на данные
		all_data[i] = temp;
		//Переходим на следующий элемент
		temp = temp->Next;
		i++;
	}
	//Пока еще есть элементы

	while (i-- > 0)
	{
		//копируем данные
		Push(all_data[i]->data);
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	delete[] all_data;
	return *this;
}
List& List::operator=(List&& _List) noexcept {
	if (this != &_List) {
		Head = _List.Head;
		Tail = _List.Tail;
		Count = _List.Count;
		_List.Head = nullptr;
		_List.Tail = nullptr;
		_List.Count = 0;
	}
	return *this;
}
List::~List()
{
	//Вызов функции удаления
	PopAll();
}
size_t List::GetCount()
{
	//Возвращаем количество элементов
	return Count;
}
void List::Push(char data)
{
//новый элемент
	Element* temp = new Element;
	//Заполняем данные
	temp->data = data;
	//Следующий - бывшая голова
	temp->Next = Head;
	//Если элемент первый, то он одновременно
	 //и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		//иначе новый элемент - головной
		Head = temp;
	Count++;
}
char List::Pop()
{
	if (Head == nullptr) {
		return char();
	}
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	if (temp == Tail) {
		Tail = nullptr;
	}
	char ret = temp->data;
	//удаляем бывший головной элемент
	delete temp;
	Count--;
	return ret;
}
void List::PopAll()
{
	//Пока еще есть элементы 
	while (Head != nullptr)
		//Удаляем элементы по одному
		Pop();
}
void List::Print()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;


	Element** all_data = new Element*[Count];

	//Пока еще есть элементы
	int i = 0;
	while (i < Count)
	{
		//сохраняем указатель на данные
		all_data[i] = temp;
		//Переходим на следующий элемент
		temp = temp->Next;
		i++;
	}
	temp = Head;
	//Пока еще есть элементы

	while (i-- > 0)
	{
		//Выводим данные
		cout << all_data[i]->data << " ";
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	delete[] all_data;
	cout << "\n\n";

}
List List::operator+(List& _List) {
	List ret;
	
	{
		Element* temp = Head;
		Element** all_data = new Element * [Count];

		int i = 0;
		while (i < Count)
		{
			all_data[i] = temp;
			temp = temp->Next;
			i++;
		}

		while (i-- > 0)
		{
			ret.Push(all_data[i]->data);
		}
		delete[] all_data;
	}
	{
		Element* temp = _List.Head;
		Element** all_data = new Element * [_List.Count];

		int i = 0;
		while (i < _List.Count)
		{
			all_data[i] = temp;
			temp = temp->Next;
			i++;
		}

		while (i-- > 0)
		{
			ret.Push(all_data[i]->data);
		}
		delete[] all_data;
	}
	return ret;

}
List List::operator*(List& _List) {
	List ret;
	Element** left_all_data = new Element * [Count];
	Element** right_all_data = new Element * [_List.Count];
	{
		Element* temp = Head;
		int i = 0;
		while (i < Count)
		{
			left_all_data[i] = temp;
			temp = temp->Next;
			i++;
		}
	}
	{
		Element* temp = _List.Head;
		int i = 0;
		while (i < _List.Count)
		{
			right_all_data[i] = temp;
			temp = temp->Next;
			i++;
		}
	}
	{
		int i = Count;
		while (i-- > 0)
		{
			bool found = false;
			int j = _List.Count;
			while (j-- > 0)
			{
				if (left_all_data[i]->data == right_all_data[j]->data) 
					found = true;
				if (found) 
					break;
			}
			if (found)
				ret.Push(left_all_data[i]->data);
		}
		delete[] left_all_data;
		delete[] right_all_data; 
	}
	return ret;
}
