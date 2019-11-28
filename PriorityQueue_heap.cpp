#include<iostream>

class PriorityQueue
{
public:
	int arraySize;
	int heapSize = 0;
	const int INF = 100000;

	PriorityQueue(int value)
	{
		arraySize = value;
	}
	void Swap(int* a, int* b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	int getRightChild(int arr[], int index)
	{
		if ((((2 * index) + 1) < arraySize) && (index >= 0))
		{
			return (2 * index) + 2;
		}
		return -1;
	}
	int getLeftChild(int arr[], int index)
	{
		if ((((2 * index) + 2) < arraySize) && (index >= 0))
		{
			return (2 * index) + 1;
		}
		return -1;
	}
	int getParent(int arr[], int index)
	{
		if ((index > 0) && (index < arraySize))
		{
			return (index / 2) - 1;
		}
		return -1;
	}
	void maxPriorityQueue(int arr[], int index)
	{
		int leftChildIndex = getLeftChild(arr, index);
		int rightChildIndex = getRightChild(arr, index);

		int temp = index;

		if ((leftChildIndex <= heapSize) && (leftChildIndex > 0))
		{
			if (arr[leftChildIndex] > arr[temp])
			{
				temp = leftChildIndex;
			}
		}
		if ((rightChildIndex <= heapSize) && (rightChildIndex > 0))
		{
			if (arr[rightChildIndex] > arr[temp])
			{
				temp = rightChildIndex;
			}
		}
		if (temp != index)
		{
			Swap(&arr[index], &arr[temp]);
			maxPriorityQueue(arr, temp);
		}
	}

	void buildMaxHeap(int arr[])
	{
		for (int i = heapSize / 2; i >= 0; i--)
		{
			maxPriorityQueue(arr, i);
		}
	}
	int max(int arr[])
	{
		return arr[0];
	}
	int extractMax(int arr[])
	{
		int max = arr[0];
		arr[0] = arr[heapSize];
		heapSize--;
		maxPriorityQueue(arr, 0);
		return max;
	}
	void increaseKey(int arr[], int index, int key)
	{
		arr[index] = key;
		while ((index > 0) && (arr[getParent(arr, index)] < arr[index]))
		{
			Swap(&arr[index], &arr[getParent(arr, index)]);
			index = getParent(arr, index);
		}
	}
	void decreaseKey(int arr[], int index, int key)
	{
		arr[index] = key;
		maxPriorityQueue(arr, index);
	}
	void insert(int arr[], int key)
	{
		heapSize++;
		arr[heapSize] = -1 * INF;
		increaseKey(arr, heapSize, key);
	}
	void printHeap(int arr[])
	{
		for (int i = 0; i < heapSize; i++)
		{
			std::cout << arr[i] << "\n";
		}
		std::cout << "\n";
	}

};

