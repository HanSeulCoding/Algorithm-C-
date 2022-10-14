#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector < pair<int, int>> bulk)
{
	vector<int> answer(bulk.size(),1);

	for (int i = 0; i < bulk.size(); ++i)
	{
		for (int j = 0; j < bulk.size(); ++j)
		{
			if (j == i)
				continue;
			if (bulk[j].first < bulk[i].first && bulk[j].second < bulk[i].second)
			{
				answer[j]++;
			}
		}
	}

	return answer;
}
int main()
{
	int num = 5;
	vector<pair<int, int>> bulk;// = { {55,185},{58,183},{88,186},{60,175},{46,155} };
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int weight;
		int tall;
		cin >> weight >> tall;
		bulk.push_back(make_pair(weight, tall));
	}

	vector<int> answer = solution(bulk);
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] <<" ";
	}
}