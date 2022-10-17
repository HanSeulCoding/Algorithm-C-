#include <iostream>
#include <string>
using namespace std;

int solution(int n)
{
	string s;
	int count = 0;
	int answer = 0;
	while (1)
	{
		s = to_string(count);
		for (int i = 0; i < s.size(); ++i)
		{
			if ((s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6'))
			{
				answer++;

				if (n == answer)
					return count;
				break;
			}
		}
		count++;
	}
}

int main()
{
	int n = 187;
	cin >> n;
	int answer = solution(n);

	cout << answer << endl;
}
