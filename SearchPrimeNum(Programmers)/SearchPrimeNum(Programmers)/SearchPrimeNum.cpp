#include <string>
#include <vector>
#include<iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> number;
map<int, bool> check;
map<int, bool> indexCheck;
bool IsPrimeNumber(int n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void Dfs(string s, string numbers, int index, int end,int& count)
{
    if (index == end)
    {
        int num = stoi(s);
        if (!check[num] && IsPrimeNumber(num))
        {
            check[num] = true;
            count++;
        }
        return;
    }
   
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (indexCheck[i])
            continue;
        
        indexCheck[i] = true;
        s += numbers[i];
        Dfs(s, numbers, index + 1, end, count);
        indexCheck[i] = false;
        s.pop_back();
    }
}
int solution(string numbers) {
    int answer = 0;
    vector<char> c;
    string s = "";
    for (int i = 1; i <= numbers.size(); ++i)
    {
        Dfs(s, numbers, 0, i, answer);
    }
   
    return answer;
}
int main()
{
    string number = "011";
    int answer = solution(number);

    cout << answer << endl;
}