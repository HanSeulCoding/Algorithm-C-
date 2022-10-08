#include <iostream>
#include <vector>

using namespace std;

int GetChangeCoin(vector<int> coins, int changeMoney)
{
	for (int i = 0; i < coins.size(); ++i)
	{
		if (changeMoney / coins[i] != 0)
			return coins[i];
	}
}
int solution(int money)
{
	int answer = 0;
	int changeMoney = 1000 - money;
	vector<int> coins = { 500,100,50,10,5,1 };
	while (changeMoney != 0)
	{
		int coin = GetChangeCoin(coins, changeMoney);
		answer += (changeMoney / coin);
		changeMoney = changeMoney % coin;
	}

	return answer;
}
int main()
{
	int money;
	int answer;

	cin >> money;

	answer = solution(money);
	cout << answer << endl;
}