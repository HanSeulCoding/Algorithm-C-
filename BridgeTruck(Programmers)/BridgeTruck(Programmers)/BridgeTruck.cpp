#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int t = 0;
    int index = 0;
    int sum = 0;
    queue<int> bridgeCrossTruck;
    queue<int> readyTruck;
    bridgeCrossTruck.push(truck_weights[0]);
    for (int i = 0; i < truck_weights.size(); ++i)
    {
        readyTruck.push(truck_weights[i]);
    }

    while (!readyTruck.empty())
    {
        int truck = readyTruck.front();
        readyTruck.pop();
        sum += truck;
        if (!readyTruck.empty())
        {
            if (readyTruck.front() + sum <= weight)
            {
                t++;
                sum += readyTruck.front();
            }
            else
            {
                t += bridge_length;
                sum += readyTruck.front();
            }
        }
    }
    answer = t;
    return answer;
}

int main()
{
    int bridge_length = 100;//2;
    int weight = 100;//10;
    vector<int> truck_weights = { 10,10,10,10,10,10,10,10,10,10}; //{ 7, 4, 5, 6 };
    int answer = solution(bridge_length, weight, truck_weights);
    cout << answer << endl;
}