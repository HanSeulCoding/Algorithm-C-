#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int sugarNum)
{
	int a = sugarNum / 5;
	int b = 0;
	while (1)
	{
		if (a < 0)
			break;
		if ((sugarNum - (a * 5))% 3 == 0)
		{
			b = (sugarNum - (a * 5)) / 3;
			break;
		}
		a--;
	}

	return a + b;
}

int main()
{
	int sugarNum = 11;
	cin >> sugarNum;
	int answer = solution(sugarNum);
	cout << answer << endl;
}