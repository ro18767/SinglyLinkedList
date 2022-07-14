#include <iostream>
using namespace std;

template <typename T>
struct Element
{
	//Данные
	T data;
	//Адрес следующего элемента списка
	Element* Next;
};
//Односвязный список
template <typename T>
class List
{
	//Адрес головного элемента списка
	Element<T>* Head;
	//Адрес концевого элемента списка
	Element<T>* Tail;
	//Количество элементов списка
	size_t Count;
public:
	//Конструктор
	List<T>();
	List<T>(const List<T>&);
	List<T>(List<T>&&) noexcept;
	List<T>& operator=(const List<T>&);
	List<T>& operator=(List<T>&&) noexcept;
	//Деструктор
	~List<T>();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Push(T);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	T Pop();
	//Удаление всего списка
	void PopAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void Print();
	//Получение количества элементов,
	//находящихся в списке
	size_t GetCount();
	List<T> operator+(List<T>&);
	List<T> operator*(List<T>&);
};


template <typename T>
List<T>::List<T>()
{
	//Изначально список пуст
	Head = Tail = nullptr;
	Count = 0;
}
template <typename T>
List<T>::List<T>(const List<T>& _List) :List() {
	//запоминаем адрес головного элемента
	Element<T>* temp = _List.Head;

	Element<T>** all_data = new Element<T> * [_List.Count];

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
template <typename T>
List<T>::List<T>(List<T>&& _List) noexcept :List<T>() {
	Head = _List.Head;
	Tail = _List.Tail;
	Count = _List.Count;
	_List.Head = nullptr;
	_List.Tail = nullptr;
	_List.Count = 0;
}
template <typename T>
List<T>& List<T>::operator=(const List<T>& _List) {
	PopAll();
	//запоминаем адрес головного элемента
	Element<T>* temp = _List.Head;

	Element<T>** all_data = new Element<T> * [_List.Count];

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
template <typename T>
List<T>& List<T>::operator=(List<T>&& _List) noexcept {
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
template <typename T>
List<T>::~List<T>()
{
	//Вызов функции удаления
	PopAll();
}
template <typename T>
size_t List<T>::GetCount()
{
	//Возвращаем количество элементов
	return Count;
}
template <typename T>
void List<T>::Push(T data)
{
	//новый элемент
	Element<T>* temp = new Element<T>;
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
template <typename T>
T List<T>::Pop()
{
	if (Head == nullptr) {
		return T();
	}
	//запоминаем адрес головного элемента
	Element<T>* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	if (temp == Tail) {
		Tail = nullptr;
	}
	T ret = temp->data;
	//удаляем бывший головной элемент
	delete temp;
	Count--;
	return ret;
}
template <typename T>
void List<T>::PopAll()
{
	//Пока еще есть элементы 
	while (Head != nullptr)
		//Удаляем элементы по одному
		Pop();
}
template <typename T>
void List<T>::Print()
{
	//запоминаем адрес головного элемента
	Element<T>* temp = Head;


	Element<T>** all_data = new Element<T> * [Count];

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
template <typename T>
List<T> List<T>::operator+(List<T>& _List) {
	List<T> ret;

	{
		Element<T>* temp = Head;
		Element<T>** all_data = new Element<T> * [Count];

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
		Element<T>* temp = _List.Head;
		Element<T>** all_data = new Element<T> * [_List.Count];

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
template <typename T>
List<T> List<T>::operator*(List<T>& _List) {
	List<T> ret;
	Element<T>** left_all_data = new Element<T> * [Count];
	Element<T>** right_all_data = new Element<T> * [_List.Count];
	{
		Element<T>* temp = Head;
		int i = 0;
		while (i < Count)
		{
			left_all_data[i] = temp;
			temp = temp->Next;
			i++;
		}
	}
	{
		Element<T>* temp = _List.Head;
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
