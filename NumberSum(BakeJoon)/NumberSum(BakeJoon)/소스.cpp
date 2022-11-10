//
#include <iostream>
#include <vector>

using namespace std;
vector<int> nums;
int solution(int n, int m)
{
	int answer = 0;
	int start = 0;
	int sum = 0;
	int end = 0;
	for (int i = 0; i < nums.size();)
	{
		if (sum >= m)
		{
			sum -= nums[start++];
		}
		else if(sum < m)
		{
			sum += nums[i++];
		}
		if (sum == m)
			answer++;
	}
  /*  while (end <= n)
    {
        if (sum >= m)
			sum -= nums[start++];
        else if (sum < m)
			sum += nums[end++];
        if (sum == m)
            answer++;
    }*/
	return answer;
}

int main()
{

	int answer = 0;
	int n;
	int m;

	cin >> n>>m;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	answer = solution(n,m);
	cout << answer << "\n";

}
