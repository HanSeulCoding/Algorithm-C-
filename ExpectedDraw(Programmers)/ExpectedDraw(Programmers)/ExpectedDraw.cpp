#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int t = a - 1;
    int k = b - 1;
    while (t / 2 != k / 2)
    {
        t = t / 2;
        k = k / 2;
        answer++;
    }

    return answer;
}

int main()
{
    int n = 8;
    int a = 4;
    int b = 7;
    int answer = solution(n, a, b);

    cout << answer << endl;
}