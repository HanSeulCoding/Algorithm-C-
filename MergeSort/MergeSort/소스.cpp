#include <iostream>
using namespace std;

int tempData[10];
void Merge(int data[], int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int k = left;
	//작은 순서대로 배열에 삽입
	while (i <= middle && j <= right)
	{
		if (data[i] <= data[j])
		{
			tempData[k] = data[i];
			++i;
		}
		else if (data[j] < data[i])
		{
			tempData[k] = data[j];
			++j;
		}
		++k;
	}

	//남은 배열 삽입
	while (i <= middle)
	{
		tempData[k] = data[i];
		++k;
		++i;
	}
	//남은 배열 삽입
	while (j <= right)
	{
		tempData[k] = data[j];
		++k;
		++j;
	}
	for (int t = left; t <= right; ++t)
	{
		data[t] = tempData[t];
	}

}
void MergeSort(int data[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		MergeSort(data, left, middle);
		MergeSort(data, middle + 1, right);
		Merge(data, left, middle, right);
	}
}
int main()
{
	int arr[10] = { 1,3,2,4,5,8,6,7,9,10 };
	MergeSort(arr, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}
}