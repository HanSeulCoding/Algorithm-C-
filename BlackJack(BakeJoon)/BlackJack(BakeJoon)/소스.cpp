#include <iostream>
#include <vector>

using namespace std;

vector<int> cards;
int maxSum = 0;
void Dfs(int count, int index, int sum,int maxNum)
{
	if (count > 3)
		return;
	if (sum > maxNum)
		return;
	if (count == 3)
	{
		maxSum = max(maxSum, sum);
		return;
	}
	for (int i = index; i < cards.size(); ++i)
	{
		Dfs(count + 1, i + 1, sum + cards[i],maxNum);
	}
}

int main()
{
	int cardNum = 0;
	int maxNum = 21;
	cin >> cardNum >> maxNum;
	for (int i = 0; i < cardNum; ++i)
	{
		int n = 0;
		cin >> n;
		cards.push_back(n);
	}
	//cards = { 5,6,7,8,9 };
	Dfs(0, 0, 0,maxNum);
	cout << maxSum << endl;
}