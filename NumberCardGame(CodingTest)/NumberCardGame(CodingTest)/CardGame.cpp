#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> CreateCard(int n)
{
	vector<int> card;
	for (int i = 0; i < n; ++i)
	{
		card.push_back(i);
	}

	return card;
}
bool isCorrect(int n, int k)
{
	if (n % k == 0)
		return true;

	return false;
}
void Dfs(int sum,int index, int indexCount, int n ,int k, int& answer, vector<int> test,vector<int> &card)
{
	if (index > card.size() - 1)
		return;
	sum += card[index];
	if (indexCount == k || indexCount == card.size() - 1)
	{
		if (isCorrect(sum, n) && indexCount == k)
		{
			answer++;
			for (int i = 0; i < test.size(); ++i)
			{
				cout << test[i] << endl;
			}
		}
		Dfs(sum, index + 1, indexCount + 1, n, k, answer, test, card);
		sum -= card[index];
		return;
	}
	//test.push_back(card[index]);
	for (int j = index; j < card.size(); ++j)
	{
		if (indexCount == 0)
		{
			if (card.size() - j < k)
				return;
		}
		test.push_back(card[index]);
	
		Dfs(sum, index + 1, indexCount + 1, n, k, answer, test, card);
		sum -= card[index];
	}
}
int solution(int n, int k)
{
	vector<int> card = CreateCard(n);
	vector<bool> visit(card.size(), 0);
	vector<int>test;
	int answer = 0;

	Dfs(0, 0, 1, n, k, answer, test, card);
	return answer;
}
int main()
{
	int n = 5, k = 3;
	int answer = 0;

	//cin >> n >> k;
	answer = solution(n, k);
	cout << answer << endl;
}