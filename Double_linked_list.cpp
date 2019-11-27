#include<iostream>
#include<string>
#include<array>

template <typename Type>
class Dlist
{
private:
	class Node
	{
	private:
		Node* prev;
		Node* next;
		Type data;
	public:
		Node()
		{
			prev = nullptr;
			next = nullptr;
		}
		~Node()
		{
			delete prev;
			delete next;
		}

		Node* getPrev()
		{
			return prev;
		}
		Node* getNext()
		{
			return next;
		}
		Type& getData()
		{
			return data;
		}
		void setPrev(Node* p)
		{
			prev = p;
		}
		void setNext(Node* n)
		{
			next = n;
		}
		void setData(Type& d)
		{
			data = d;
		}
	};
	Node* first;
	Node* last;
	int lenght;

public:
	Dlist()
	{
		Node* temp = new Node();
		first = temp;
		last = temp;
		lenght = 0;
	}
	Dlist(Dlist& other)
	{
		Node* temp = new Node();
		first = temp;
		last = temp;
		lenght = 0;
		Node* current = other.first->getNext();
		for (int i = 0; i < other.lenght; ++i)
		{
			append(current->getData());
			current = current->getNext();
		}
	}
	Dlist operator=(Dlist& other)
	{
		Dlist swap = (*new Dlist(other));
		return swap;
	}
	int size()
	{
		return lenght;
	}
	bool empty()
	{
		if (lenght == 0) return true;
		return false;
	}
	void print()
	{
		Node* current = first;
		std::cout << "{";
		for (int i = 0; i < lenght - 1; i++)
		{
			current = current->getNext();
			std::cout << current->getData() << ",";
		}
		current = current->getNext();
		std::cout << current->getData() << "}" << std::endl;
	}
	void insert(int index, Type value)
	{
		if (index > lenght) throw "what the unicorn..bro, Index out of bounds";

		Node* newNode = new Node();
		newNode->setData(value);

		if (index == lenght)
		{
			last->setNext(newNode);
			newNode->setPrev(last);
			last = newNode;
			lenght++;
		}
		Node* current = first->getNext();
		for (int i = 0; i < index; i++)
		{
			current = current->getNext();
		}
		newNode->setPrev(current->getPrev());
		newNode->setNext(current));
		current->getPrev()->setNext(newNode);
		current->setPrev(newNode);
		lenght++;
	}
	void prepend(Type value)
	{
		insert(0, value);
	}
	void append(Type value)
	{
		insert(lenght, value);
	}

	Type& get(int index)
	{
		if (empty()) throw "oppsy....empty list";
		int realIndex = index % lenght;
		Node* current = first->getNext();
		for (int i = 0; i < realIndex; ++i) {
			current = current->getNext();
		}

		return current->getData();
	}
	Type& front()
	{
		if (empty()) throw "list is empty";
		return first->getNext()->getData();
	}
	Type& back()
	{
		if (empty()) throw "list is empty";
		return last->getdata();
	}
	int search(Type value)
	{
		if (empty()) return -1;

		Node* current = first;
		for (int i = 0; i < lenght; i++)
		{
			if (current->getData() == value) return i;
			current = current->getNext();
		}
		std::cout << std::endl << value << " is not in the list";
		return -1;
	}
	void del(int index)
	{
		if (index >= lenght || index < 0) return 0;
		Node* current = first->getNext();
		if (index == lenght - 1)
		{
			last = last->getPrev();
			current = last->getNext();
			current->getPrev()->setNext(nullptr);
			lenght--;
		}
		for (int i = 0; i < index i++) { current = current->getNext(); }
		current->getPrev()->setNext(current->getNext());
		current->getNext()->setPrev(current->getPrev());
		lenght--;
	}
	void popFront()
	{
		if (empty()) return;
		del(0);
	}
	void popBack()
	{
		if (empty()) return;
		del(lenght - 1);
	}

	~Dlist()
	{
	}
};

