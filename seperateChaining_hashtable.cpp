#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>

#define DEFAULT 1024

struct Node 
{
private:
	friend class HashTable;
	Node* next;
	int data;
public:
	Node() {}
	
	Node(int d, Node* n) 
	{
		data = d;
		next = n;
	}
};
class HashTable 
{
public:
	int size;
	std::vector<Node*>* list;
	HashTable(int s) 
	{
		size = s;
		list = new std::vector<Node*>(size);
	}
	HashTable() 
	{
		size = DEFAULT;
		list = new std::vector<Node*>(size);
	}

	void insert(int data) 
	{
		int index = hash(data);
		if (list->at(index) == NULL)
		{
			list->at(index) = new Node(data, NULL);
		}
		Node* newNode = list->at(index);
		while (!newNode->data == NULL)
		{
			if (newNode->next == NULL)
			{
				newNode->next = new Node(data, NULL);
				break;
			}
			newNode = newNode->next;
		}
	}
	void remove(int data)
	{
		int index = hash(data);
		
		if (list->at(index) == NULL) throw "no data in that index";
		else
		{
			Node* pos = list->at(index);
			Node* temp;
			while (!pos == NULL)
			{
				if (pos->data == data)
				{
					temp = pos->next;
					pos = NULL;
					pos = temp;
					break;
				}
				pos = pos->next;
			}
		}
	}
	int getSize()
	{
		return size;
	}
	int hash(int data)
	{
		a = (a + 0x7ed55d16) + (a << 12);
		a = (a ^ 0xc761c23c) ^ (a >> 19);
		a = (a + 0x165667b1) + (a << 5);
		a = (a + 0xd3a2646c) ^ (a << 9);
		a = (a + 0xfd7046c5) + (a << 3);
		a = (a ^ 0xb55a4f09) ^ (a >> 16);
		return abs(a % getSize());
	}
	void print(int start)
	{
		int lineCount = 0;
		for (int i = start; i < list->size(); i++)
		{
			std::cout << "\t";
			Node* pos = list->at(i);
			while (!pos == NULL)
			{
				std::cout << pos->data << " ";
				pos = pos->next;
			}
			std::cout << std::endl;
		}
	}
};
