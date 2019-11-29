#include<iostream>
#include<vector>

class UnionFind
{
private:
	int size;
	std::vector<int> id;
	std::vector<int> sz;
	int numComponents;
public:
	UnionFind(int size)
	{
		if (size <= 0) throw "Illegal size.";
		this->size = this->numComponents = size;
		sz.resize(size);
		id.resize(size);

		for (int i = 0; i < size; i++)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int p)
	{
		int root = p;
		while (root != id[root])
			root = id[root];
		while (p != root)
		{
			int next = id[p];
			id[p] = root;
			p = next;
		}
		return root;
	}
	bool Connected(int p, int q)
	{
		return Find(p) == Find(q);
	}

	int componentSize(int p)
	{
		return sz[Find(p)];
	}

	int size()
	{
		return size;
	}

	int components()
	{
		return numComponents;
	}

	void Unify(int p, int q)
	{
		int rootOne = Find(p);
		int rootTwo = Find(q);

		if (sz[rootOne] > sz[rootTwo])
		{
			sz[rootOne] += sz[rootTwo];
			id[rootTwo] = rootOne;
		}
		else
		{
			sz[rootTwo] += sz[rootOne];
			id[rootOne] == rootTwo;
		}
		numComponents--;
	}
};
