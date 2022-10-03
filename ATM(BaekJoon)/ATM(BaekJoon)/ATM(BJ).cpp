#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priority)
{
	int sum = 0;
	int result = 0;
	sort(priority.begin(), priority.end());
	for (int i = 0; i < priority.size(); ++i)
	{
		sum += priority[i];
		result += sum;
	}
	return result;
}
int main()
{
	vector<int> priority;
	int inputCount;

	cin >> inputCount;
	for (int i = 0; i < inputCount; ++i)
	{
		int a;
		cin >> a;
		priority.push_back(a);
	}
	int answer = solution(priority);
	cout << answer << endl;

}