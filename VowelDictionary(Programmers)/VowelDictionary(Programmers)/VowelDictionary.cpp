#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dictionary;
void Dfs(int length, string s, vector<char> vowel)
{
    if (length == s.size())
    {
        dictionary.push_back(s);
        return;
    }
    for (int i = 0; i < 5; ++i)
    {
        Dfs(length, s + vowel[i], vowel);
    }
}

int CreateDic(vector<char> vowel, string word)
{
    for (int i = 1; i <= 5; ++i)
    {
        string s = "";
        Dfs(i,s,vowel);
    }
    
    sort(dictionary.begin(), dictionary.end());

    for (int i = 0; i < dictionary.size(); ++i)
    {
        if (dictionary[i] == word)
            return i + 1;
    }
    return 0;
}
int solution(string word) {
    int answer = 0;
    vector<char> vowel;
    vowel.push_back('A');
    vowel.push_back('E');
    vowel.push_back('I');
    vowel.push_back('O');
    vowel.push_back('U');

    answer = CreateDic(vowel,word);
    return answer;
}

int main()
{
    string word = "AAAAE";
    int result = solution(word);

    cout << result << endl;
}