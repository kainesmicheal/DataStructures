#include<iostream>

class Node
{
public:
	Node* prev;
	Node* next;
	int data;
	
	Node(int value)
	{
		prev = next = nullptr;
		data = value;
	}
};

class Dlist 
{
public:
	Node* head;
	Node* tail;

	Dlist()
	{
		head = tail = nullptr;
	}
	~Dlist()
	{
		destroy();
	}
	void pushBack(int& value)
	{
		Node* newNode = (Node*)malloc(sizeof(Node(value)));
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	void destroy()
	{
		Node* node = head;
		while (node)
		{
			Node* ptr = node;
			node = node->next;
			delete ptr;
		}
		head = tail = nullptr;
	}
};

class Stack
{
public:
	int maxSize;
	int count;
	Dlist list;

	Stack(int size)
	{
		count = 0;
		maxSize = size;
	}

	void Push(int a)
	{
		if (count < maxSize)
		{
			list.pushBack(a);
			count++;
		}
	}

	void Pop()
	{
		Node* tail = list.tail;
		if (tail == NULL) throw "Empty.";
		if (tail == list.head)
		{
			delete tail;
			list.head = list.tail = nullptr;
			count++;
		}
		else
		{
			Node* ptr = list.tail->prev;
			delete list.tail;
			list.tail = ptr;
			list.tail->next = nullptr;
			count--;
		}
	}
	void display()
	{
		Node* ptr = list.head;
		while (ptr)
		{
			std::cout << ptr->data << ",";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	Stack stack(5);
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);
	stack.Push(8);
	stack.Pop();
	stack.display();
}


