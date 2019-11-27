#include<iostream>

template<typename Type, int Size>
class DynamicArray
{
private:
	Type* arr;
	int len = 0;    // lenght user thinks the array is
	int capcity = Size;   // Actual lenght

public:
	DynamicArray()
	{
		arr = new Type[Size];
	}
	DynamicArray(int cap)
	{
		if (cap < 0) throw "Illegal Capasity...";
		this.capacity = cap;
		arr = new Type[cap];
	}
	int size()
	{
		return len;
	}
	bool isEmpty()
	{
		return size() == 0;
	}
	Type get(int index)
	{
		return arr[index];
	}
	void set(int index, Type value)
	{
		arr[index] = value;
		len = len + 1;
	}
	void clear()
	{
		for (int i = 0; i < len; i++) arr[i] = NULL;
		len = 0;
	}
	void add(Type value)
	{
		if (len + 1 >= capcity)
		{
			if (capcity == 0) capcity = 1;
			else capcity = capcity * 2;  //Doubling the size of the current array
			Type* newArray = new Type[capcity];
			for (int i = 0; i < len; i++) newArray[i] = arr[i];
			arr = newArray; //new array is now linked
		}

		arr[len] = value; //value is added to the len+1 index
		len = len + 1;
	}

	Type delbyIndex(int index)
	{
		if (index >= len || index < 0) throw "what the unicorn..bro...index out fo bounds!";
		Type deletedData = arr[index];
		Type* newArray = new Type[len];
		for (int i=0,j = 0; i < len; i++, j++)
		{
			if (i == index) j--;
			else newArray[j] = arr[i];
		}
		arr = newArray;
		capcity = len - 1;
		return deletedData;
	}
	// == operator overloading to comapare to objects
	/*bool operator== (DynamicArray& ar, int index)
	{
		if (arr[index] == ar[index]) return true;
		else return false;
	}*/
	int indexOf(Type value)
	{
		for (int i = 0; i < len; i++)
		{
			if (value == NULL)
			{
				if (arr[i] == NULL) return i;
			}
			else
			{
				if (arr[i] == value) return i;
			}

		}
		return -1;
	}
	bool delbyVal(int value)
	{
		int index = indexOf(value);
		if (index == -1) return false;
		delbyIndex(index);
		return true;
	}


};


int main()
{
	DynamicArray<int, 4> array;
	
	array.set(0, 2);
	array.set(1, 3);
	array.set(2, 4);
	array.set(3, 5);
	array.add(6);
	int c = array.get(4);
	array.delbyIndex(1);
	int v = array.get(1);
	int in = array.indexOf(6);
	array.delbyVal(6);
	int vv = array.get(2);
	
		
}