#include <iostream>

class SinglyLinkedList
{
public:
	struct Node
	{
		int data;
		Node* next;
		Node();
	};

private:
	Node* head;
	Node* tail;
	int count;

public:
	SinglyLinkedList();
	~SinglyLinkedList();


	void AddToHead(int data);

	void AddToTail(int data);

	void InsertInto(int data, int position);
	void DeleteFromHead();

	void DeleteFromTail();

	void DeleteByIndex(int position);

	void Clear();

	void Print() const;

	int GetCount() const;

	int IndexOf(int data) const;

};
