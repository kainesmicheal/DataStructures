#include<iostream>

class FenwickTree
{
	int* tree;
public:

	FenwickTree(int size)
	{
		tree = new int[size + 1];

		for (int i = 0; i <= size; i++)
		{
			tree[i] = 0;
		}
	}

	int* construct(int a[], int n)
	{
		
		for (int i = 0; i <= n; i++)
		{
			updateTree(tree, n, i, a[i]);
		}

		return tree;
	}

	void updateTree(int* tr, int n, int i, int val)
	{
		i++;
		while (i <= n)
		{
			tr[i] += val;
			i += i & (-1);
		}
	}
	int getSum(int* tr, int i)
	{
		int sum = 0;
		i++;

		while (i > 0)
		{
			sum += tr[i];
			i -= i & (-i);
		}
		return sum;
	}

};