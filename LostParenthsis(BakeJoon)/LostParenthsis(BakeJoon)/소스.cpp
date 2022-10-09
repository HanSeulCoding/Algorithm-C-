#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
	vector<int> nums;
	string temp;

	int sum = 0;
	bool isMinus = false;
	for (int i = 0; i < s.length(); ++i)
	{
		temp += s[i];
		if (s[i] == '-' || s[i] == '+'
			|| i == s.length() - 1)
		{
			int num = stoi(temp);
			if (!isMinus)
			{
				sum += num;
			}
			if (isMinus)
			{
				sum -= num;
			}
			temp = "";
		}
		if (s[i] == '-')
		{
			isMinus = true;
		}

	}

	return sum;
}

int main()
{
	string s;

	cin >> s;
	int answer = solution(s);

	cout << answer << endl;
}