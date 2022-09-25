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
    sum = truck_weights[0];
    while (!bridgeCrossTruck.empty())
    {
        int truck = bridgeCrossTruck.front();
        t++;

        if (t == bridge_length) //트럭이 다리를 다 건넜다는 얘기.
        {
            bridgeCrossTruck.pop();
            if (index < truck_weights.size())
            {
                bridgeCrossTruck.push(truck_weights[++index]);
            }
        }
        else
        {
            if (index + 1 < truck_weights.size() && sum + truck_weights[index + 1] < weight)
            {
                sum += truck_weights[index + 1];
                bridgeCrossTruck.push(truck_weights[index]+1);
                index++;
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