#include<iostream>

template<typename type>
class Stack
{
private:
	struct Node
	{
		type data;
		Node* next;
	};

	Node* head = NULL;
public:
	void Push(type value)
	{
		Node* newNode = (Node*) malloc(sizeof(Node));
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}
	void Pop()
	{
		if (head == NULL) std::cout << "Stack UnderFlow." << std::endl;
		std::cout << "The Poped value was " << head->data << std::endl;
		head = head->next;
	}
	void display()
	{
		Node* ptr;
		if (head == NULL) std::cout << "Empty stack." << std::endl;
		ptr = head;
		while (!ptr == NULL)
		{
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	Stack<int> node;
	node.Push(10);
	node.Push(11);
	node.Push(12);
	node.Pop();
	node.display();

}