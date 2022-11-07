#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long>length;
vector<long long> prices;
vector<pair<long long, long long>> priceIndex;
vector<bool> check(100001,0);

bool Compare(pair<long long, long long> x, pair<long long, long long> y)
{
	return x.first < y.first;
}
void Dfs(long long index , long long &answer)
{
	//���� ���� �ε����� ��������Ѵ�.

	if (index == prices.size())
		return;

	if (!check[priceIndex[index].second])
	{
		long long lengthSum = 0;
		for (int i = priceIndex[index].second/*���� ���� Index*/; i < prices.size() - 1; ++i)//���� �������������� �״��� ���������� ���ݰ��
		{
			if (check[i] == true)
			{
				break;
			}
			check[i] = true;
			lengthSum += (long long)length[i];
		}
		answer += (long long)(lengthSum * priceIndex[index].first);
	}

	index++;
	Dfs(index, answer);
}
long long solution()
{
	long long answer = 0;
	
	for (int i = 0; i < prices.size(); ++i)
	{
		priceIndex.push_back(make_pair(prices[i], i));
	}
	sort(priceIndex.begin(), priceIndex.end(),Compare);

	Dfs(0, answer);

	return answer;
}

int main()
{
	int num = 7;
    cin >> num;
	/*length = { 3,4,2,2,4,5 };
	prices = { 8,9,5,4,2,7,1,};*/
	for (int i = 0; i < num - 1; ++i)
	{
		long long roadLengty;
		cin >> roadLengty;
		length.push_back(roadLengty);
	}
	for (int i = 0; i < num; ++i)
	{
		long long price;
		cin >> price;
		prices.push_back(price);
	}

	long long answer = solution();

	cout << answer << endl;
}