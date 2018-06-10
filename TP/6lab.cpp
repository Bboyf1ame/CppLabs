#include <iostream>
using namespace std;

struct Node
{
	int x;
	Node *left;
	Node *right;
};

Node *addnode(int x, Node *node)
{
	if (node == NULL)
	{
		node = new Node;
		node->x = x;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		if (x < node->x)
		{
			node->left = addnode(x, node->left);
		}
		else
		{
			node->right = addnode(x, node->right);
		}
	}
	return node;
}

void Print(Node *node)
{
	if (node != NULL)
	{
		Print(node->left);
		cout << node->x << endl;
		Print(node->right);
	}
}
Node *FindNodeMax(Node *node)
{
	if (node->right == NULL)
	{
		return node;
	}
	else
	{
		return FindNodeMax(node->right);
	}
}


Node *deleteNode(int x, Node *node, int &y)
{
	if (node != NULL)
	{
		if (x == node->x)
		{
			Node *tmp = NULL;
			if (node->left == NULL && node->right == NULL)
			{
				tmp = node;
				node = NULL;
				delete tmp;
			}
			else
			{
				if (node->left == NULL)
				{
					tmp = node;
					node = node->right;
					delete tmp;
				}
				else
				{
					if (node->right == NULL)
					{
						tmp = node;
						node = node->left;
						delete tmp;
					}
					else
					{
						Node *tmp = NULL;
						tmp = FindNodeMax(node->left);
						node->x = tmp->x;
						tmp = NULL;
					}
				}
			}
		}
		else
		{
			y++;
			if (x < node->x)
			{
				node->left = deleteNode(x, node->left, y);
			}
			else
			{
				node->right = deleteNode(x, node->right, y);
			}
		}
	}
	else
	{
		cout << "”зел с таким значением не был найден" << endl;
	}
	return node;
}


int main()
{
	setlocale(LC_ALL, "");
	Node *tree = NULL;
	int x, y = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << "¬ведите значение: ";
		cin >> x;
		if (x > 0)
		{
			tree = addnode(x, tree);
		}
		else
		{
			cout << "«начение < 0" << endl;
			i--;
		}
	}
	cout << "¬ведите значение удал€емого узла: ";
	cin >> x;
	tree = deleteNode(x, tree, y);
	Print(tree);
	system("pause");
}