#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> GetDivisor(int n) //약수 구하기
{
    vector<int> divisors;

    for (int i = 1; i <= (int)sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(n / i);
            divisors.push_back(i);
        }
    }

    return divisors;
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisors = GetDivisor(brown + yellow);
    bool isComplete = false;
    for (int i = 0; i < divisors.size(); ++i)
    {
        for (int j = 0; j < divisors.size(); ++j)
        {
          /*  if (i == j)
                continue;*/
            if (divisors[i] >= divisors[j] &&
                divisors[i] * divisors[j] == (brown + yellow))
            {
                if ((divisors[i] - 2) * (divisors[j] - 2) == yellow)
                {
                    answer.push_back(divisors[i]);
                    answer.push_back(divisors[j]);
                    isComplete = true;
                    break;
                }   
            }

        }
        if (isComplete)
            break;
    }

    return answer;
}

int main()
{
    int brown = 10;
    int yellow = 2;
    vector<int> answer = solution(brown, yellow);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}