#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

void AddDictionary(string s, map<string, int>& lzwMap, int endNum)
{
    if (lzwMap.count(s) == 0)
        lzwMap.insert({ s,endNum });
}
string GetNextString(string msg, map<string, int>& lzwMap, int index, int &endNum)
{
    string s = "";
    string prevS;
    for (int i = index; i < msg.size(); ++i)
    {
        s += msg[i];
        if (lzwMap.count(s) == 0)
        {
            AddDictionary(s, lzwMap, endNum+1);
            endNum++;
            return prevS;
        }
        prevS = s;
    }
    return s;
}
vector<int> Compress(map<string, int> &lzwMap, string msg)
{
    vector<int> answer;
    int count = 1;
    int endNum = 26;
    string nextString = "";
    for (int i = 0; i < msg.size(); ++i)
    {
       
        nextString = GetNextString(msg, lzwMap, i, endNum);
        if (lzwMap.count(nextString) != 0)
        {
            answer.push_back(lzwMap[nextString]);
            if (lzwMap[nextString] == 27)
                cout << "hanseul" << endl;
        }
        i += nextString.size() - 1; //2개짜리가 Dic에 있을때 건너뛰어줘야한다. 
    }
    return answer;
}
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> lzwMap;

    string s;
    for (int i = 0; i < 26; ++i)
    {
        char c = (char)(i + 65);
        string s(1,c);
        lzwMap.insert(make_pair(s, i + 1));
    }
    answer = Compress(lzwMap, msg);
    return answer;
}

int main()
{
    string msg = "TOBEORNOTTOBEORTOBEORNOT";
    vector<int> answer = solution(msg);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] <<endl;
    }
}