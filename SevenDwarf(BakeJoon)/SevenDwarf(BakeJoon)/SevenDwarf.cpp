#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void Dfs(int index , int sum, stack<int> sevenDwarf,vector<int> Dwarf,
	vector<int> &answer)
{
	if (index > 9)
		return;
	if (sum > 100)
		return;
	if (sum == 100 && sevenDwarf.size() == 7 && answer.size() == 0)
	{
		while (!sevenDwarf.empty())
		{
			answer.push_back(sevenDwarf.top());
			sevenDwarf.pop();
		}
		return;
	}
	for (int i = index; i < 9; ++i)
	{
		sevenDwarf.push(Dwarf[i]);
		sum += Dwarf[i];
		Dfs(i + 1, sum, sevenDwarf, Dwarf, answer);
		sum -= Dwarf[i];
		sevenDwarf.pop();
	}
	return ;
}
vector<int> solution(vector<int> Dwarf)
{
	stack<int> sevenDwarf;
	vector<int> answer;
	Dfs(0, 0, sevenDwarf, Dwarf,answer);
	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	vector<int> Dwarf;
	vector<int> answer;

	for (int i = 0; i < 9; ++i)
	{
		int dwarf;
		cin >> dwarf;
		Dwarf.push_back(dwarf);
	}
	answer = solution(Dwarf);
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}
}