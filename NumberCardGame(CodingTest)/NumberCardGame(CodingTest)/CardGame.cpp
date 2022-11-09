#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N = 2, K = 2;
long long dp[201][201];

using namespace std;

vector<int> CreateCard(int n)
{
	vector<int> c;
	for (int i = 0; i < n; ++i)
	{
		c.push_back(i);
	}

	return c;
}
bool isCorrect(int n, int k)
{
	if (n % k == 0)
		return true;

	return false;
}
//void Dfs(int sum,int index, int indexCount, int& answer, vector<int>& card)
//{
//	if (indexCount == k)
//	{
//		if (isCorrect(sum, n))
//		{
//			answer = (answer + 1) % 1000000007;
//		}
//		return;
//	}
//	for (int i = index; i < card.size(); ++i)
//	{
//		if (i == 0 && card.size() - i < k)
//			return;
//		Dfs((sum + card[i]) % 1000000007, i + 1, indexCount + 1, answer,card);
//	}
//}
int solution()
{
	vector<int> card = CreateCard(N);
	vector<bool> visit(card.size(), 0);
	vector<int>test;
	int answer = 0;
	for (int i = 0; i <= N; ++i)
	{
		dp[1][i] = 1;
	}
	//Dfs(0, 0, 0,answer,card);
	for (int k = 2; k <= K; ++k)
	{
		for (int n = 0; n <= N; ++n)
		{
			for (int i = 0; i <= n; ++i)
			{
				dp[k][n] = dp[k][n] + dp[k - 1][n-i];
			}
			dp[k][n] = dp[k][n] % 1000000;
		}
	}
	cout << dp[K][N];
	return answer;
}
int main()
{
	int answer = 0;

	//cin >> n >> k;
	answer = solution();
	cout << answer << endl;
}