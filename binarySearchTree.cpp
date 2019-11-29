#include<iostream>

struct Node
{
	int data;
	Node* parent;
	Node* left;
	Node* right;
	Node()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		data = NULL;
	}
	Node(int value)
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		data = value;
	}

};

class BinarySearchTree
{
private:
	Node* root;

	void initializeNode(Node* node, int value) 
	{
		node->data = value;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
	}

	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			std::cout << node->data << " ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->left);
			std::cout << node->data << " ";
			inOrder(node->right);
		}
	}
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->left);
			postOrder(node->right);
			std::cout << node->data << " ";
		}
	}
	Node* searchTree(Node* node, int value)
	{
		if (node == nullptr || value == node->data)
		{
			return node;
		}

		if (value < node->data)
		{
			return searchTree(node->left, value);
		}
		else
		{
			return searchTree(node->right, value);
		}
	}
	Node* deleteNode(Node* node, int value)
	{
		if (node == nullptr) return node;
		else if (value < node->data) node->left = deleteNode(node->left, value);
		else if (value > node->data) node->right = deleteNode(node->right, value);
		else
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				node = nullptr;
			}

			else if (node->left == nullptr)
			{
				Node* swap = node;
				node = node->right;
				delete swap;
			}

			else if (node->right == nullptr)
			{
				Node* swap = node;
				node = node->left;
				delete swap;
			}

			else
			{
				Node* swap = minNode(node->right);
				node->data = swap->data;
				node->right = deleteNode(node->right, swap->data);
			}
		}
		return node;
	}
	void print(Node* root)
	{
		if (root != nullptr)
		{
			std::cout << root->data << std::endl;
			print(root->left);
			print(root->right);
		}
	}
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void createTree()
	{
		Node* n50 = new Node;
		initializeNode(n50, 50);
		Node* n30 = new Node;
		initializeNode(n30, 30);
		Node* n70 = new Node;
		initializeNode(n70, 70);

		n30->parent = n50;
		n70->parent = n50;
		n50->left = n30;
		n50->right = n70;

		//add new nodes here

		this->root = n50;
	}

	void pre()
	{
		preOrder(this->root);
	}
	void in()
	{
		inOrder(this->root);
	}
	void post()
	{
		postOrder(this->root);
	}
	Node* search(int value)
	{
		return searchTree(this->root, value);
	}
	Node* minNode(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}
	Node* maxNode(Node* node)
	{
		while(node->right != nullptr)
		{
			node = node->right;
		}
		return node;
	}
	Node* getRoot()
	{
		return this->root;
	}
	Node* delNode(int data)
	{
		return deleteNode(this->root, data);
	}
};