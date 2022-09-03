#include<iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> wires;
void Dfs(int n,int &count,vector<bool> check) //연결되어진 노드의 갯수를 구한다. 
{
    if (check[n])
        return;

    check[n] = true;
    count++;
    for (int i = 0; i < wires.size(); ++i)
    {
        if (wires[i][0] == n)
        {
            Dfs(wires[i][1],count,check);
        }
        if (wires[i][1] == n)
        {
            Dfs(wires[i][0],count,check);
        }
    }
}
int solution(int n, vector<vector<int>> wire) {
    int answer = 101;
    int count = 0;
    int prevN = 0;
    vector<bool> check(102, 0);
    wires = wire;
    int test = 0;

    for (int i = 0; i < wires.size(); ++i)
    {
        prevN = wires[i][1]; 
        wires[i][1] = 101; //간선을 끊어준다. 
        int a = 0;
        int b = 0;
        Dfs(wires[i][0], a, check); //끊어짐을 당한 노드에 연결되어진 노드의 갯수를 구해준다. 
        Dfs(prevN, b, check);
        int temp = abs(a - (b+1));
        answer = min(temp, answer);
        wires[i][1] = prevN;
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> wires =
    /*{
        {1,2},{2,3},{3,4}
    };*/
   /* { {1,3},{2,3},{3,4},{4,5}
    ,{4,6},{4, 7},{7,8},{7,9} };*/
    {
        {1, 2}, { 2,7 }, { 3,7 }, { 3,4 }, { 4,5 }, { 6,7 }
    };

    int answer = solution(n, wires);
    cout << answer << endl;
}