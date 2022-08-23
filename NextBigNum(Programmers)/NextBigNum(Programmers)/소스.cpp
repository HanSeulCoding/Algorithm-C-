#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> getNotationNum(int n)
{
    vector<int> notationNum;

    while (n != 0)
    {
        notationNum.push_back(n % 2);
        n = n / 2;
    }
    reverse(notationNum.begin(), notationNum.end());
    return notationNum;

}
bool IsEqualOne(int n, int oneNum)
{
    int count = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n = n / 2;
    }
    if (oneNum == count)
        return true;

    return false;
}
int solution(int n) {
    int answer = 0;
    vector<int> notationNum = getNotationNum(n);
    int oneNum = 0;
    for (int i = 0; i < notationNum.size(); ++i)
    {
        if (notationNum[i] == 1)
            oneNum++;
    }
    for (int i = n + 1; i <= 1000000; ++i)
    {
        if (IsEqualOne(i, oneNum))
        {
            answer = i;
            break;
        }
    }
    return answer;
}
int main()
{
    int n = 15;
    int answer = solution(n);

    cout << answer << endl;
}