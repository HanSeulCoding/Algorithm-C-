#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int Factor(int a)
{
    for (int i = 2; i <= (int)sqrt(a); ++i)
    {
        if (a % i == 0 && a / i <= 10000000)
            return a / i;
    } 
    return 1;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; ++i)
    {
        if (i == 1)
            answer.push_back(0);
        else
        {
            answer.push_back(Factor(i));
        }
    }
    return answer;
}
int main()
{
    //1,000,000,000
    //index 가 소수면 1 아니면 번째 /2;
    long long begin = 10;
    long long end = 20;
    vector<int> answer = solution(begin, end);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}