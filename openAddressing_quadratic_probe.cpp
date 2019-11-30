#include<iostream>
#include<cstdlib>

enum EntryType
{
	legiZero, empOne, delTwo
};

struct HashTableEntry
{
	int value;
	EntryType info;
};
struct HashTable
{
	int size;
	HashTableEntry* t;
};
bool isPrime(int value)
{
	if (value == 2 || value == 3) return true;
	if (value == 1 || value % 2 == 0) return false;
	bool prime = true;
	for (int i = 3; i <= value; i++ )
	{
		prime = true;
		for (int j = 3; j < i; j++)
		{
			if (i % j == 0)
			{
				bool prime = false;
				break;
			}
		}
	}
	if (prime) return true;
	else return false;
}
int nextPrime(int value)
{
	if (value <= 0) value == 3;
	if (value % 2 == 0) value++;
	for (; !isPrime(value); value += 2);
	return value;
}
int HashFunc(int key, int value)
{
	return key % value;
}
HashTable* initiateTable(int size)
{
	HashTable* ht;
	if (size < 10)
	{
		std::cout << "Table size is small" << std::endl;
		return NULL;
	}
	ht = new HashTable;
	if (ht == NULL)
	{
		std::cout << "NOthing in this table" << std::endl;
		return NULL;
	}
	ht->size = nextPrime(size);
	ht->t = new HashTableEntry[ht->size];
	if (ht->t == NULL)
	{
		std::cout << "table is still small" << std::endl;
		return NULL;
	}
	for (int i = 0; i < ht->size; i++)
	{
		ht->t[i].info = empOne;
		ht->t[i].value = NULL;
	}
	return ht;
}
int searchKey(int key, HashTable* ht)
{
	int index = HashFunc(key, ht->size);
	int collisions = 0;
	while (ht->t[index].info != empOne && ht->t[index].value != key)
	{
		index = index + 2 * ++collisions - 1;
		if (index >= ht->size) index -= ht->size;
	}
	return index;
}
void Insert(int key, HashTable* ht)
{
	int index = searchKey(key, ht);
	if (ht->t[index].info != legiZero)
	{
		ht->t[index].info = legiZero;
		ht->t[index].value = key;
	}
}
HashTable* ReHash(HashTable* ht)
{
	int size = ht->size;
	HashTableEntry* tempTable = ht->t;
	ht = initiateTable(2 * size);
	for (int i = 0; i < size; i++)
	{
		if (tempTable[i].info == legiZero)
		{
			Insert(tempTable[i].value, ht);
		}
		free(tempTable);
		return ht;
	}
}
void display(HashTable* ht)
{
	for (int i = 0; i < ht->size; i++)
	{
		int value = ht->t[i].value;
		if (!value)
		{
			std::cout << "Position: " << i + 1 << "NUll " << std::endl;
			std::cout << "Position: " << i + 1 << value << std::endl;
		}
	}
}





