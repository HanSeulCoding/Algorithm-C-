#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp(60001, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1])% 1000000007 + dp[i - 2] % 1000000007;
    }
    answer = dp[n];
    return answer % 1000000007;
}

int main()
{
    int n = 4;
    int answer = solution(n);

    cout << answer << endl;
}