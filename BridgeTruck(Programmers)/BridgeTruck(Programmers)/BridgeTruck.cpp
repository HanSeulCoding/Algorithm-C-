#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0;
    int sum = 0;
    queue<int> bridgeCrossTruck;

    while (true)
    {
        if (index == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        int truck = truck_weights[index];
        answer++;

        // Truck이 다리위를 지났을경우 
        if (bridgeCrossTruck.size() == bridge_length)
        {
            sum -= bridgeCrossTruck.front();
            bridgeCrossTruck.pop();
        }
        //다리위 Truck보다 Truck 무게가 나갔을경우
        if (sum + truck <= weight)
        {
            sum += truck;
            bridgeCrossTruck.push(truck);
            index++;
        }
        else
        {
            bridgeCrossTruck.push(0);
        }
    }

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