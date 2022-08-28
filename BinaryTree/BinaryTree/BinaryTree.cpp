#include<iostream>
#include<string>

using namespace std;

class Node
{
	int n = 0;
	Node* left = NULL;
	Node* right = NULL;
public:
	Node(int n, Node* left = NULL, Node* right = NULL)
	{
		this->n = n;
		this->left = left;
		this->right = right;
	}
	void LinkNode(Node* left, Node* right)
	{
		this->left = left;
		this->right = right;
	}
	void PreOrder(Node* node)
	{
		if (node != NULL)
		{
			Print(node);
			PreOrder(node->left);
			PreOrder(node->right);
		}
	}
	void InOrder(Node* node)
	{
		if (node != NULL)
		{
			InOrder(node->left);
			Print(node);
			InOrder(node->right);
		}
	}
	void PostOrder(Node* node)
	{
		if (node != NULL)
		{
			PostOrder(node->left);
			PostOrder(node->right);
			Print(node);
		}
	}

	void Print(Node* node)
	{
		cout << node->n <<" ";
	}
};

int main()
{
	Node* a = new Node(1,new Node(2,new Node(4),new Node(5)),new Node(3,new Node(6),new Node(7)));
	cout << "전위순회: ";
	a->PreOrder(a);
	cout << endl;
	cout << "중위순회: ";
	a->InOrder(a);
	cout << endl;
	cout << "후위순회: ";
	a->PostOrder(a);
	cout << endl;
	
}