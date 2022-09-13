#include<iostream>
#include <vector>
using namespace std;
void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void QuickSort(int *data, int start, int end)
{
	if (start >= end)
		return;
	
	int left = start + 1;
	int right = end;
	int *pivot = &data[start];
	while (left <= right)
	{
		while (left <= end && data[left] <= *pivot)
		{
			left++;
		}
		while (right > start && data[right] >= *pivot)
		{
			right--;
		}
		if (right < left) //엇갈린상태!!
			Swap(&data[right], pivot);
		else //엇갈리지 않은상태
		{
			Swap(&data[right], &data[left]);
		}
	}

	QuickSort(data, start, right - 1);
	QuickSort(data, right + 1, end);
}
int main()
{
	int arr[10] = { 1,5,3,2,6,8,9,10,4,7 };
	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}
}