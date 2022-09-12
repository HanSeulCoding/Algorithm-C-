#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (count == 0)
        {
            if (s[i] == ')')
                return false;
        }
        if (s[i] == ')')
        {
            count = count - 1;
        }
        else if (s[i] == '(')
        {
            count = count + 1;
        }
    }
    if (count != 0)
        return false;
    return answer;
}

int main()
{
    string s = ")()(";
    bool answer = solution(s);
    cout << answer << endl;
}