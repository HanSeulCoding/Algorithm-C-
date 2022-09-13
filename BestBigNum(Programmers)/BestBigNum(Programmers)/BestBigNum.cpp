#include<string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
    string S_a = to_string(a);
    string S_b = to_string(b);

    return S_a + S_b > S_b + S_a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int count = 0;
    sort(numbers.begin(), numbers.end(), Compare);
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == 0)
            count++;
        answer += to_string(numbers[i]);
    }
    if (count == numbers.size())
        answer = answer[0];
    return answer;
}

int main()
{
    vector<int> numbers = { 0,0,0,0 };
    string answer = solution(numbers);
    cout << answer << endl;
}