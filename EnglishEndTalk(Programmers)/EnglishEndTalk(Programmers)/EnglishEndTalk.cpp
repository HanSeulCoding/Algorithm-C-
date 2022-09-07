#include<iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (words[j] == words[i])
            {
                int num = (i + 1) % n == 0 ? n : (i + 1) % n;
                int order = (i + 1) % n == 0 ? (i + 1) / n : ((i + 1) / n) + 1;
                answer.push_back(num);
                answer.push_back(order);
                return answer;
            }
        }
        if (i + 1 < words.size() && words[i][words[i].size() - 1] != words[i + 1][0])
        {
            int num = (i + 2) % n == 0 ? n : (i + 2) % n;
            int order = (i + 2) % n == 0 ? (i + 2) / n : ((i + 2) / n) + 1;
            answer.push_back(num);
            answer.push_back(order);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main()
{
    int n = 2;
    vector<string> words =
        //  { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
      //{ "hello", "one", "even", "never", "now", "world", "draw" };
   // { "tank","tank"};
    { "land","dream","mom","mom","ror" };
    vector<int> answer = solution(n, words);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}