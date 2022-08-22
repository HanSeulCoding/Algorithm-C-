#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); ++i)
    {
        land[i][0] += max(land[i-1][1], max(land[i-1][2], land[i-1][3]));
        land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] += max(land[i-1][0], max(land[i-1][1], land[i-1][3]));
        land[i][3] += max(land[i-1][0], max(land[i-1][2], land[i-1][1]));
    }
    int a = max(land[land.size()-1][0], land[land.size() - 1][1]);
    int b = max(land[land.size() - 1][2], land[land.size() - 1][3]);
    answer = max(a, b);
    return answer;
}
int main()
{
    vector<vector<int> > land = { {1,2,3,4}, {2,3,4,10} , {4,3,2,1} };
    int answer = solution(land);

    cout << answer << endl;

}