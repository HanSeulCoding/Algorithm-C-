#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> coins, int money)
{
	reverse(coins.begin(), coins.end());
	int answer = 0;
	int i = 0;
	while (money != 0)
	{
		if (money / coins[i] == 0)
		{
			++i;
			continue;
		}

		answer += (money / coins[i]);
		money = money % coins[i];
	}

	return answer;
}
int main()
{
	int num;
	int money;
	int answer = 0;
	vector<int> coins;

	cin >> num >> money;
	for (int i = 0; i < num; ++i)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	answer = solution(coins , money);
	cout << answer;
}