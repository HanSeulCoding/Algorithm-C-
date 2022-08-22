
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

bool IsPrimeNum(long long n)
{
    if (n == 0 || n == 1)
        return false;
    int count = 0;
    for (int i = 2; i <= (int)sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
queue<int> GetNotationNum(int n, int k)
{
    int mok = 0;
    int namuge = 0;
    queue<int> notationNum;
    while (n > 0)
    {
        mok = n / k;
        namuge = n % k;
        notationNum.push(namuge);
        n = mok;
    }
    return notationNum;
}
int solution(int n, int k) {

    long long indexCount = 1;
    long long num = 0;
    int answer = -1;
    int count = 0;
    queue<int> notationQ = GetNotationNum(n, k);

    while (!notationQ.empty())
    {
        int n = notationQ.front();
        notationQ.pop();
        if (n != 0)
        {
            num += n * indexCount;
            indexCount *= 10;
        }
        if (n == 0 || notationQ.empty())
        {
            indexCount = 1;

            if (IsPrimeNum(num))
            {
                count++;
            }
            num = 0;
        }
    }

    return count;
}
int main()
{
    int n = 101;
    int k = 10;
    int result = solution(n, k);

    cout << result << endl;
}


