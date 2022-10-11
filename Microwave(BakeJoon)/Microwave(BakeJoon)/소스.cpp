#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int time)
{
	vector<int> answer = { 0,0,0 };
	int i = 0; 
	vector<int> btnTimes = { 300, 60 ,10 };
	while (time != 0 && i < btnTimes.size())
	{
		if (time / btnTimes[i] == 0)
		{
			++i;
			continue;
		}
		answer[i] = (time / btnTimes[i]);
		time %= btnTimes[i];
	}
	if (time != 0)
	{
		answer = { 0,0,0 };
	}
	return answer;
}

int main()
{
	int time = 189;
	cin >> time;
	vector<int> answer;
	bool isCook = false;
	answer = solution(time);

	for (int i = 0; i < answer.size(); ++i)
	{
		if (answer[i] != 0)
		{
			isCook = true;
		}
	}
	if (isCook)
	{
		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}
}