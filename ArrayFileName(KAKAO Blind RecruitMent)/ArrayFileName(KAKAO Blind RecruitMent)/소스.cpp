#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
struct File
{
    string head;
    string number_S;
    int number_I;
    string tail;
};
void DivideString(string files, string &head, string &number, string &tail) //head, number, tail ºÐÇØ
{
    bool isHeadCheck = false;
    bool isNumCheck = false;
    int headIndex;
    int numberIndex;
    for (int i = 0; i < files.size(); ++i)
    {
        if (isdigit(files[i]) != 0 && !isHeadCheck)
        {
            headIndex = i;
            head = files.substr(0, i);
            isHeadCheck = true;
        }
        if (isHeadCheck && isdigit(files[i]) != 0)
        {
            number += files[i];
            isNumCheck = true;
            //break;
        }
        if (isNumCheck && isdigit(files[i]) == 0)
        {
            tail = files.substr(i,files.size());
            break;
        }
    }
}
string ToLower(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
bool Compare(File a, File b)
{
    string aHead = ToLower(a.head);
    string bHead = ToLower(b.head);
    if (aHead == bHead)
    {
        return a.number_I < b.number_I;
    }

    return aHead < bHead;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> files_S;
 
    for (int i = 0; i < files.size(); ++i)
    {
        File file;
        string head;
        string number;
        string tail;
        DivideString(files[i], head, number, tail);
        file.head = head;
        if (number != "")
        {
            file.number_I = stoi(number);
        }
        file.number_S = number;
        file.tail = tail;
        files_S.push_back(file);
    }
    stable_sort(files_S.begin(), files_S.end(), Compare);
    for (int i = 0; i < files_S.size(); ++i)
    {
        string temp = files_S[i].head + files_S[i].number_S + files_S[i].tail;
        answer.push_back(temp);
    }
    return answer;
}
int main()
{
    vector<string> files = { "F-0000.000", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" ,"MUZI01.zip","muzi1.png"};
        //{ {"img12.png"}, {"img010.png"}, {"img02.png"}, {"img1.png"}, {"IMG01.GIF"}, {"img2.JPG"} };
    vector<string> answer = solution(files); 

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}