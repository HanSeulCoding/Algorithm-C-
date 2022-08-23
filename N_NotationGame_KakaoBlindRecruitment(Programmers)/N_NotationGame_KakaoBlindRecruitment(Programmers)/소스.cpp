#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <string>
using namespace std;

string GetNotationNum(int n, int k, int t,int p, int m, int &count, int &count2)
{
    string s;
    string a;
    int namuge = 0;
    if (n == 0)
    {
        s += 0 + 48;
    }
    while (n != 0)
    {
        namuge = n % k;
        if (namuge >= 10)
            s += namuge + 55;
        else
        {
            s += namuge + 48;
        }
        n = n / k;
    }
    reverse(s.begin(), s.end());
    int i = 0;
    while (i < s.size())
    {
        if (count == p)
        {
            if (count2 == t)
                return a;
            a += s[i];
            count2++;
        }
        if (count % m == 0)
            count = 0;
        
        n = n / k;
        ++i;
        count++;
    }

    return a;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp;
    int count = 1;
    int count2 = 0;
    int i = 0; 

    while (count2 != t)
    {
        answer += GetNotationNum(i, n,t, p, m, count, count2);
        ++i;
    }
    return answer;
}
int main()
{
    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;
    string answer = solution(n, t, m, p);
    cout << answer << endl;
}