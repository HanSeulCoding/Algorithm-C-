#include <stdio.h>
#include <stdlib.h>
// ���� 1
// �� �Է� �� : "hello world"
// ��ȯ �� : world hello

void Reverse(char* output, int outputArraySize, const char* input)
{
	int index = 0;

	for (int i = 0; i < outputArraySize; ++i)
	{
		if (input[i] == ' ')
		{
			index = i;
		}
	}

	for (int i = 0; i < outputArraySize; ++i)
	{
		if (index > i)
		{
			int tempIndex = (index + 1) + i;
			output[i] = input[tempIndex];
		}
		if (index == i)
		{
			output[i] = ' ';
		}
		else if(index < i)
		{
			int tempIndex = i - (index + 1);
			output[i] = input[tempIndex];
		}
	}
	output[outputArraySize] = NULL;
}

// ���� 2
// int �� ���� ���� �Է� �޾� ���ڿ��� ��ȯ �ϴ� �Լ�
// �� �Է� ��: 4714, "4714"
void IntToStr(char* output, int outputArraySize, int input)
{
	int count = 0;
	int tenGob = 1;
	while (input / tenGob != 0)
	{
		tenGob *= 10;
		count++;
	}
	tenGob *= 0.1f;
	for (int i = 0; i < count; ++i)
	{
		output[i] = (input / tenGob) + '0';
		input %= tenGob;
		tenGob *= 0.1f;
	}
	output[outputArraySize] = NULL;
}
// ���� 3
// Insertion Sort������ؼ� ���� ���� ������ ������List�� ���� ��,
// ����head�� ��ȯ�ϴ� �Լ��� ���弼��.
// <��>
// �Է°�: head��2��10��7��6��20
// ��ȯ�� : head��2��6��7��10��20
struct ListNode
{
	int val;
	ListNode* nextNode;
	ListNode(int x, ListNode* next) : val(x), nextNode(next) {}
};
ListNode* InsertionSort(ListNode* head)
{
	ListNode* currentNode = head;

	while (currentNode != NULL)
	{
		ListNode* initHead = head;
		int value = currentNode->val;

		while (initHead != currentNode )
		{
			if (initHead->val > currentNode->val)
			{
				int temp = initHead->val;
				initHead->val = currentNode->val;
				currentNode->val = temp;
			}
			initHead = initHead->nextNode;
		}
		currentNode = currentNode->nextNode;
	}

	return head;
}


//void Print(ListNode* head)
//{
//	ListNode* currentNode = head;
//	while (currentNode != NULL)
//	{
//		printf("%d ", currentNode->val);
//		currentNode = currentNode->nextNode;
//	}
//}
// ���� 4
// �ð����⵵�� �����Ͽ� �־���List�� ����������n��°Node�� ã���ÿ�.
// <��>
// �Է°�: head��2��1��3��6��10��5, 2��°
// ��ȯ�� : 10
bool CheckingNodeLast(ListNode* node, int n)
{
	ListNode* temp = node;
	int count = 1;


	for (int i = 0; i < n; ++i)
	{
		temp = temp->nextNode;
	}
	if (temp == NULL)
		return true;

	return false;
}
// ù��° ���
//ListNode* FindNthNodeFromLast(ListNode* head, int n)
//{
//	ListNode* currentNode = head;
//	
//	while (currentNode != NULL)
//	{
//		ListNode* temp = currentNode;
//		if (CheckingNodeLast(currentNode, n))
//		{
//			return currentNode;
//		}
//		currentNode = currentNode->nextNode;
//	}
//	if (currentNode == NULL)
//	{
//		printf("%d ��°�� ã�� �� �����ϴ�. ");
//	}
//	return currentNode;
//}
// �ι�° ��� //�޸𸮸� �� ��������� �ð����⵵��O(N)�̴�.
ListNode* FindNthNodeFromLast(ListNode* head, int n)
{
	ListNode* currentNode = head;
	ListNode** listAddress = (ListNode**)malloc(sizeof(ListNode)*n);
	int i = 0;
	int listSize = 0;
	while (currentNode != NULL)
	{
		listAddress[i] = currentNode;
		currentNode = currentNode->nextNode;
		listSize++;
		i++;
	}
	return listAddress[listSize - n];
}
//���� 5
// preorder���ָ� �ϸ鼭 ����� ���� ����Ͻÿ�.
// <��>
// �Է°�:
//     10
//   /     \
//  7      16
// / \    / \
// 2  8  11 18
// ��ȯ��: 10, 7, 2, 8, 16, 11, 18
struct TreeNode
{
	int val;
	TreeNode* leftNode;
	TreeNode* rightNode;
	TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), leftNode(left), rightNode(right) {}
};
void Print(TreeNode* node)
{
	printf("%d ", node->val);
}
void PreorderTraversal(TreeNode* root)
{
	if (root != NULL)
	{
		Print(root);
		PreorderTraversal(root->leftNode);
		PreorderTraversal(root->rightNode);
	}
}
// ���� 6
// �� �� ����X�� ������ �������� ���� ���ڰ� �����ؼ�2�� ������int�迭�� �ֽ��ϴ�.
// �ð����⵵�� ����Ͽ� �ѹ��� ������ ����X�� ã�ƺ�����.
// <��>
// �Է°�: [2, 2, 4, 4, 6, 6, 3, 1, 1, 7, 7]
// ��ȯ�� : 3
//int FindSingleNumber(int* numbers, int arraySize)
//{
//	int* check = (int*)malloc(sizeof(int) * arraySize);
//	int answer = 0;
//	for (int i = 0; i < arraySize; ++i)
//	{
//		check[i] = 0;
//	}
//	for (int i = 0; i < arraySize; ++i)
//	{
//		check[numbers[i]]++;
//	}
//	for (int i = 0; i < arraySize; ++i)
//	{
//		if (check[numbers[i]] == 1)
//		{
//			answer = numbers[i];
//		}
//	}
//	return answer;
//}
int FindSingleNumber(int* numbers, int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		if (numbers[i] == numbers[i + 1])
		{
			i += 1;
		}
		else
		{
			return numbers[i];
		}
	}
}
int main()
{
	//���� 1 
	/*char input[] = "hello World";
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 11;
	Reverse(output, 11, input);
	printf("%s\n", output);*/

	//���� 2
	/*int input = 4714;
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 4;
	IntToStr(output, outputArraySize, input);
	printf("%s", output);*/

	//���� 3
	//ListNode* head = new ListNode(1, new ListNode(2, new ListNode(20, new ListNode(5, new ListNode(10, new ListNode(8, NULL))))));
	/*head = InsertionSort(head);
	Print(head);*/

	//���� 4
	/*ListNode* head = new ListNode(3, new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(6, new ListNode(10, new ListNode(5,NULL)))))));
	ListNode* find = FindNthNodeFromLast(head, 5);
	printf("%d", find->val);*/

	//���� 5
	/*TreeNode* treeNode = new TreeNode(10, new TreeNode(7, new TreeNode(2), new TreeNode(8)), new TreeNode(16, new TreeNode(11), new TreeNode(18)));
	PreorderTraversal(treeNode);*/

	//���� 6
	int array[] = {2,2,4,4,6,6,3,1,1,7,7};

	int answer = FindSingleNumber(array, 11);
	printf("%d", answer);
}