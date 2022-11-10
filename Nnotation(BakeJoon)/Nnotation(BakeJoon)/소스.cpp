#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string Solution(int n, int notation)
{
	int namuge;
	string answer="";
	while (n != 0)
	{
		namuge = n % notation;
		char c;
		if (namuge >= 10)
		{
			c = 65 + namuge - 10;
		}
		else
		{
			c = namuge + '0';
		}
		answer += c;
		n /= notation;
	}

	reverse(answer.begin(), answer.end());
	return answer;
}
int main()
{
	int n ;
	int notation;
	string answer;

	cin >> n;
	cin >> notation;
	if (n == 0)
		answer += '0';
	else
	{
		answer = Solution(n, notation);
	}

	cout << answer << endl;
}