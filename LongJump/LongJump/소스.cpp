#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> dp(n+1, 0);

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] % 1234567  + dp[i - 2] % 1234567;
    }
    
    return dp[n];
}

int main()
{
    int n = 2000;
    int answer = solution(n);
    cout << answer << endl;
}