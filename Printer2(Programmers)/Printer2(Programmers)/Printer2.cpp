#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int maxIndex = 0;
    int max = -1;
    priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;

    for (int i = 0; i < priorities.size(); ++i)
    {
        if (max < priorities[i])
        {
            max = priorities[i];
            maxIndex = i;
        }
    }
    for (int i = maxIndex; i < priorities.size(); ++i)
    {
        pair<int, int> temp;
        temp.first = i;
        temp.second = priorities[i];
        pq.push(temp);
    }
    for (int i = 0; i < maxIndex; ++i)
    {
        pair<int, int> temp;
        temp.first = i;
        temp.second = priorities[i];
        pq.push(temp);
    }
    queue<pair<int, int>> tempQ;
    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        answer++;
        if (temp.first == location)
        {
            break;
        }
    }
    return answer + 1;

    
}

int main()
{
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };//{ 2,1,3,2 };
    int location = 0;//2;

    int answer = solution(priorities, location);
    cout << answer << endl;
}