#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int GetPowerNum(int n, map<long long, int>& dp)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;

    dp.insert({ n,GetPowerNum(n / 2,dp) + n % 2 });
    return dp[n];
}
int solution(int n)
{
    int ans = 0;
    map<long long, int> dp_map;
    ans = GetPowerNum(n, dp_map);

    return ans;
}
int main()
{
    long long n = 10000000000;
    int answer = solution(n);
    cout << answer << endl;
}