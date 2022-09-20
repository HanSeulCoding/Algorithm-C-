#include <stdio.h>
#include <stdlib.h>
// 문제 1
// 예 입력 값 : "hello world"
// 반환 값 : world hello

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

// 문제 2
// int 형 정수 값을 입력 받아 문자열로 반환 하는 함수
// 예 입력 값: 4714, "4714"
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
// 문제 3
// Insertion Sort를사용해서 작은 값이 앞으로 오도록List를 정렬 후,
// 다음head를 반환하는 함수를 만드세요.
// <예>
// 입력값: head→2→10→7→6→20
// 반환값 : head→2→6→7→10→20
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
// 문제 4
// 시간복잡도를 염두하여 주어진List의 마지막에서n번째Node를 찾으시오.
// <예>
// 입력값: head→2→1→3→6→10→5, 2번째
// 반환값 : 10
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
// 첫번째 방법
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
//		printf("%d 번째는 찾을 수 없습니다. ");
//	}
//	return currentNode;
//}
// 두번째 방법 //메모리를 더 사용하지만 시간복잡도가O(N)이다.
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
//문제 5
// preorder종주를 하면서 노드의 값을 출력하시오.
// <예>
// 입력값:
//     10
//   /     \
//  7      16
// / \    / \
// 2  8  11 18
// 반환값: 10, 7, 2, 8, 16, 11, 18
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
// 문제 6
// 단 한 숫자X를 제외한 나머지는 같은 숫자가 연속해서2번 나오는int배열이 있습니다.
// 시간복잡도를 고려하여 한번만 나오는 숫자X를 찾아보세요.
// <예>
// 입력값: [2, 2, 4, 4, 6, 6, 3, 1, 1, 7, 7]
// 반환값 : 3
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
	//문제 1 
	/*char input[] = "hello World";
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 11;
	Reverse(output, 11, input);
	printf("%s\n", output);*/

	//문제 2
	/*int input = 4714;
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 4;
	IntToStr(output, outputArraySize, input);
	printf("%s", output);*/

	//문제 3
	//ListNode* head = new ListNode(1, new ListNode(2, new ListNode(20, new ListNode(5, new ListNode(10, new ListNode(8, NULL))))));
	/*head = InsertionSort(head);
	Print(head);*/

	//문제 4
	/*ListNode* head = new ListNode(3, new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(6, new ListNode(10, new ListNode(5,NULL)))))));
	ListNode* find = FindNthNodeFromLast(head, 5);
	printf("%d", find->val);*/

	//문제 5
	/*TreeNode* treeNode = new TreeNode(10, new TreeNode(7, new TreeNode(2), new TreeNode(8)), new TreeNode(16, new TreeNode(11), new TreeNode(18)));
	PreorderTraversal(treeNode);*/

	//문제 6
	int array[] = {2,2,4,4,6,6,3,1,1,7,7};

	int answer = FindSingleNumber(array, 11);
	printf("%d", answer);
}