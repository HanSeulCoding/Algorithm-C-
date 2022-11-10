#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s[] = { "0","1","10","11","100","101","110","111" };
	string temp[] = { "000","001","010","011","100","101","110","111" };

	string num;
	string answer = "";
	cin >> num;


	answer += s[num[0] - '0'];

	for (int i = 1; i < num.size(); ++i)
	{
		if (i == 0)
		{
			answer += s[(num[i] - '0')];
		}
		else
		{
			answer += temp[(num[i] - '0')];
		}
	}


	cout << answer << endl;
}