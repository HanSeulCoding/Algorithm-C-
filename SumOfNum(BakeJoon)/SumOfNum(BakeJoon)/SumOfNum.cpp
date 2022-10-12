#include <iostream>
#include <vector>

using namespace std;

long long solution(long long num)
{
	long long answer = 0;
	long long sum = 0;
	int i = 1;
	while (sum <= num)
	{
		sum += i;
		i++;
		answer++;
	}

	return answer - 1;
}

int main()
{
	long long answer = 0;
	long long num = 190;
	cin >> num;
	answer = solution(num);

	cout << answer << endl;
}