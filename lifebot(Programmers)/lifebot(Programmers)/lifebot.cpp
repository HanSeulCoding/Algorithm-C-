#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int index = 0;

    sort(people.begin(), people.end());
    
    while (index < people.size())
    {
        int temp = people.back();
        people.pop_back();
        if (temp + people[index] <= limit)
        {
            index++;
        }
        answer++;
    }
    return answer;
}

int main()
{
    vector<int> people = { 70,50,80,50 };
    int limit = 100;
    int answer = solution(people, limit);

    cout << answer << endl;
}