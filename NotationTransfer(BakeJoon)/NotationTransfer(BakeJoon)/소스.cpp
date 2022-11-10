#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s, int notation)
{
	int answer = 0;
	int temp = notation;
	reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); ++i)
	{
		int n = 0;
		if (s[i] >= 65 && s[i] <= 90)
		{
			n = s[i] - 55;
		}
		else
		{
			n = s[i] - '0';
		}
		if (i == 0)
		{
			answer += n;
		}
		else
		{
			answer += (n * notation);
			notation *= temp;
		}
	}
	return answer;
}

int main()
{
	string s = "ZZZZZ";
	int notaion = 36;
	int answer;
	cin >> s >> notaion;
	answer = solution(s, notaion);

	cout << answer << endl;
}