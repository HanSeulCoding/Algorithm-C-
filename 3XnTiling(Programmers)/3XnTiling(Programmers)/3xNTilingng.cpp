#include<iostream>
#include <string> 
#include <vector>
#include <map>

using namespace std;

#define MODULER 1000000007

int solution(int n) {

    int answer = 0;
    vector<long long>dp(5010, 0);
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] = dp[i] + dp[j] * 2;
        }

        dp[i] = dp[i] % MODULER;
    }
    return dp[n];
}

int main()
{
    int n = 4;
    int answer = solution(n);
    cout << answer << endl;
}