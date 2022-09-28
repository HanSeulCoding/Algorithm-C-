#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return false;
        return a.second < b.second;
    }
};

bool Compare2(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int maxIndex = 0;
    int max = -1;
    int count = 0;
    queue<pair<int, int>> q;
    priority_queue <int> pq;


    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        int index = temp.first;
        int value = temp.second;
        q.pop();

        if (pq.top() == value)
        {
            pq.pop();
            answer++;
            if (index == location)
            {
                break;
            }
        }
        else
            q.push(make_pair(index, value));
    }
    return answer;
}

int main()
{
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };//{ 2,1,3,2 };;
    int location = 0;

    int answer = solution(priorities, location);
    cout << answer << endl;
}