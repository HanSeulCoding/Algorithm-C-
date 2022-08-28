#include<string>
#include<vector>
#include<iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; ++i)
    {
        int mok = i / n;
        int namuge = i % n;

        if (mok > namuge)
        {
            answer.push_back(mok + 1);
        }
        else
            answer.push_back(namuge + 1);
    }
    return answer;
}

int main()
{
    int n = 3;
    long long left = 2;
    long long right = 5;
    vector<int> answer = solution(n, left, right);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }

}