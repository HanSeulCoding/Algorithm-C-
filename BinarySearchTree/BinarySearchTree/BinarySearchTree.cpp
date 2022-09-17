#include <iostream>

using namespace std;
struct Node
{
	int data;
	Node* leftNode = NULL;
	Node* rightNode = NULL;

	Node(int data, Node* leftNode, Node* rightNode)
	{
		this->data = data;
		this->leftNode = leftNode;
		this->rightNode = rightNode;
	}
};

class BinarySearchTree
{
private:
	Node* head;

public:
	BinarySearchTree(Node* head)
	{
		this->head = head;
	}
	bool Search(Node* node, int data)
	{
		if (node == NULL)
			return false; 

		if (node->data == data)
			return true;
		else if (node->data > data)
		{
			return Search(node->leftNode, data);
		}
		else if (node->data < data)
		{
			return Search(node->rightNode, data);
		}
		return false;
	}

	void Insert(Node* tree, int data)
	{
	
		if (data < tree->data)
		{
			if (tree->leftNode == NULL)
			{
				Node* node = new Node(data, NULL, NULL);
				tree->leftNode = node;
				return;
			}
			else
				Insert(tree->leftNode, data);
		}
		
		else if (data > tree->data)
		{
			if (tree->rightNode == NULL)
			{
				Node* node = new Node(data, NULL, NULL);
				tree->rightNode = node;
				return;
			}
			else
				Insert(tree->rightNode, data);
		}
	}
	Node* GetMinDataNode(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->leftNode == NULL)
		{
			return node;
		}
		else
		{
			return GetMinDataNode(node->leftNode);
		}
	}
	void Delete(Node* tree, Node* parent, int target)
	{
		if (tree == NULL)
			return;

		Node* removeNode = NULL;

		if (tree->data > target)
		{
			Delete(tree->leftNode, tree, target);
		}
		else if (tree->data < target)
		{
			Delete(tree->rightNode, tree, target);
		}
		else if (tree->data == target)
		{
			removeNode = tree;

			if (tree->leftNode == NULL && tree->rightNode == NULL)
			{
				if (parent->leftNode == tree)
				{
					parent->leftNode = NULL;
				}
				if (parent->rightNode == tree)
				{
					parent->rightNode = NULL;
				}
			}

			else if (tree->leftNode == NULL || tree->rightNode == NULL)
			{
				Node* temp;
				if (tree->leftNode != NULL)
				{
					temp = tree->leftNode;
				}
				else
				{
					temp = tree->rightNode;
				}

				if (parent->leftNode == tree)
				{
					parent->leftNode = temp;
				}
				else
					parent->rightNode = temp;
			}

			else if (tree->leftNode != NULL && tree->rightNode != NULL)
			{
				Node* minNode = GetMinDataNode(tree->rightNode);
				int data = minNode->data;
				Delete(tree, NULL, minNode->data);
				tree->data = data;
			}
		}
	}
	void PreOrder(Node * node)
	{
		if (node != NULL)
		{
			Print(node);
			PreOrder(node->leftNode);
			PreOrder(node->rightNode);
		}
	}

	void InOrder(Node* node)
	{
		if (node != NULL)
		{
			InOrder(node->leftNode);
			Print(node);
			InOrder(node->rightNode);
		}
	}

	void PostOrder(Node* node)
	{
		if (node != NULL)
		{
			PostOrder(node->leftNode);
			PostOrder(node->rightNode);
			Print(node);
		}
	}

	void Print(Node* node)
	{
		cout << node->data << " ";
	}
	Node* GetHead()
	{
		return head;
	}
};
int main()
{
	BinarySearchTree bst(new Node(23,NULL,NULL));
	bst.Insert(bst.GetHead(), 11);

	bst.Insert(bst.GetHead(), 139);
	bst.Insert(bst.GetHead(), 1);
	bst.Insert(bst.GetHead(), 16);
	bst.Insert(bst.GetHead(), 13);
	bst.Insert(bst.GetHead(), 20);
	bst.Insert(bst.GetHead(), 67);
	bst.Insert(bst.GetHead(), 70);

	bst.Delete(bst.GetHead(), NULL, 11);
	cout << "Search °á°ú : " << bst.Search(bst.GetHead(),11) << endl;

	bst.PreOrder(bst.GetHead());
}