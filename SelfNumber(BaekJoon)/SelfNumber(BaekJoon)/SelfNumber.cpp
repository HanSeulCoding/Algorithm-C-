#include <iostream>
#include <vector>

using namespace std;

int GetDigitSum(int num)
{
	int i = 10000;
	int sum = 0;
	while (num != 0)
	{
		if (num / i == 0)
		{
			i *= 0.1f;
			continue;
		}
		sum += (num / i);
		num = num % i;
	
		i *= 0.1f;
	}

	return sum;
}
vector<int> GetSelfNum()
{
	int n = 1;
	vector<bool> notDigitNum(10001,0);
	vector<int> selfNum;

	while (n < 10000)
	{
		int sum = GetDigitSum(n);
	
		if (n + sum < 10000)
		{
			notDigitNum[n + sum] = true; //자릿수와 + n을 더한 값 True
		}
		n++;
	}
	for (int i = 1; i < 10000; ++i)
	{
		if (!notDigitNum[i])
		{
			selfNum.push_back(i); 
		}
	}
	return selfNum;
}
int main()
{
	vector<int> selfNum;
	selfNum = GetSelfNum();

	for (int i = 0; i < selfNum.size(); ++i)
	{
		cout << selfNum[i] << endl;
	}
}