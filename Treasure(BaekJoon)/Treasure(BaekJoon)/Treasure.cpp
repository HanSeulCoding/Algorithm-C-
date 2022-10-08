#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Compare(int a, int b)
{
	return a > b;
}
int solution(vector<int> a, vector<int> b)
{
	int answer = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), Compare);

	for (int i = 0; i < a.size(); ++i)
	{
		answer += (a[i] * b[i]);
	}

	return answer;
}
int main()
{
	vector<int> a;
	vector<int> b;
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < num; ++i)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	int answer = solution(a, b);

	cout << answer << endl;
}