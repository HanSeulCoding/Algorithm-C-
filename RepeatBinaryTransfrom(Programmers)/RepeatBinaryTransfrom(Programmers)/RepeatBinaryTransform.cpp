#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string Binary(int n) //이진 변환
{
    string s;
    while (n != 0)
    {
        int mok = n / 2;
        int namuge = n % 2;
        s += to_string(namuge);
        n = mok;
    }
    reverse(s.begin(), s.end());
    return s;
}
int GetSize(string s, int & removeZeroNum) //모든 0의 갯수와 1의 갯수를 count 하는 함수
{
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '1')
        {
            count++;
        }
        else if (s[i] == '0')
            removeZeroNum++;
    }

    return count;
}
void Dfs(int size, string s, int &removeZeroNum, int &repeatCount)
{
    if (size == 1)
        return;
    
    repeatCount++;
    size = GetSize(s, removeZeroNum);
    s = Binary(size);
    Dfs(size, s, removeZeroNum, repeatCount);
}
vector<int> solution(string s) {
    vector<int> answer;
    
    int removeZeroNum = 0;
    int repeatCount = 0;

    Dfs(0, s, removeZeroNum, repeatCount);

    answer.push_back(repeatCount);
    answer.push_back(removeZeroNum);

    return answer;
}

int main()
{
    string s = "110010101001";

    vector<int> answer = solution(s);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}