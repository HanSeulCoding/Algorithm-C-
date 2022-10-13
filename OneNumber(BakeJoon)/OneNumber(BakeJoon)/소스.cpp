#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsOneNum(int num)
{
	int digit = 0;
	int minus = 0;
	vector<int> digits;
	string s = to_string(num);

	for (int i = 0; i < s.size(); ++i)
	{
		digits.push_back(s[i] - '0');
	}
	if (digits.size() < 3) //100보다 작은 수는 무조건 한수
	{
		return true;
	}
	minus = digits[0] - digits[1];
	for (int i = 1; i < digits.size(); ++i)
	{
		if (i + 1 < digits.size())
		{
			if (minus != digits[i] - digits[i + 1]) //그 전의 자릿수 차와 다르다면 한수X
			{
				return false;
			}
			minus = digits[i] - digits[i + 1];
		}
	}

	return true;
}
int solution(int num)
{
	int answer = 0;
	for (int i = 1; i <= num; ++i)
	{
		if (IsOneNum(i))
		{
			answer++;
		}
	}
	return answer;
}

int main()
{
	int num = 500;
	cin >> num;
	int answer = solution(num);
	
	cout << answer << endl;
}