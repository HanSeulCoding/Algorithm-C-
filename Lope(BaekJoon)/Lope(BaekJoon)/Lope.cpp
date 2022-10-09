#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Compare(int a, int b)
{
	return a > b;
}
int solution(vector<int> lopes)
{
	int answer = 0;
	int maxLopes;
	int minLopes;

	sort(lopes.begin(), lopes.end(),Compare);
	
	for (int i = 1; i <= lopes.size(); ++i)
	{
		lopes[i - 1] = lopes[i - 1] * i;
	}
	sort(lopes.begin(), lopes.end(), Compare);

	answer = lopes[0];
	return answer;
}
int main()
{
	int num = 2;
	int answer = 0;
	cin >> num;

	vector<int> lopes;
	for (int i = 0; i < num; ++i)
	{
		int lope;
		cin >> lope;
		lopes.push_back(lope);
	}

	answer = solution(lopes);
	cout << answer << endl;
}