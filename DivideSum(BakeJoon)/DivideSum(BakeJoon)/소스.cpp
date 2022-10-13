#include <iostream>
#include <vector>

using namespace std;

int GetDigitSum(int n)
{
	int i = 1000000;
	int sum = 0;
	while (n != 0)
	{
		if (n / i == 0)
		{
			i *= 0.1f;
			continue;
		}
		sum += (n / i);
		n = n % i;
	}

	return sum;
}
int solution(int n)
{
	int answer = 0;
	int i = 0;
	while (true)
	{
		int sum = i + GetDigitSum(i);
		
		if (i > n)
		{
			answer = 0;
			break;
		}
		if (sum == n)
		{
			answer = max(i, answer);
			break;
		}
		++i;
	}
	return answer;
}

int main()
{
	int n = 216;
	cin >> n;
	int answer = solution(n);

	cout << answer << endl;
}