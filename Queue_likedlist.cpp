#include<iostream>


class List
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* front = NULL;
	Node* rear = NULL;
	Node* swap;
public:
	void Add(int value)
	{
		if (rear == NULL)
		{
			rear = (Node*) malloc(sizeof(Node));
			rear->data = value;
			rear->next = NULL;
			front = rear;
		}
		else
		{
			swap = (Node*) malloc(sizeof(Node));
			rear->next = swap;
			swap->data = value;
			swap->next = NULL;
			rear = swap;
		}
	}
	void Del()
	{
		swap = front;
		if (front == NULL) throw "Under Flow.";
		if (swap->next != NULL)
		{
			swap = front->next;
			std::cout << "Deleted value " << front->data << std::endl;
			free(front);
			front = swap;
		}
		else
		{
			std::cout << "Deleted value " << front->data << std::endl;
			free(front);
			front = rear = NULL;
		}
	}
	void Display()
	{
		swap = front;
		if (front == NULL && rear == NULL) throw "Empty queue.";
		std::cout << "{";
		while (!swap == NULL)
		{
			std::cout << " " << swap->data << " " ;
			swap = swap->next;

		}
		std::cout << "}" <<  std::endl;
	}

};
int main()
{
	List queue;
	queue.Add(5);
	queue.Add(6);
	queue.Add(7);
	queue.Add(8);
	queue.Del();
	queue.Display();
}