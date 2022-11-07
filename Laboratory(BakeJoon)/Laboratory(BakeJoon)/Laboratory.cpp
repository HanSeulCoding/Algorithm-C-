#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct VirusPos
{
	int n = 0;
	int m = 0;
	int value = 0;
};
void InfectionLab(vector<vector<int>> labMap, vector<VirusPos> virusPos)
{
	int dirX[4] = { 0,1,0,-1 }; //위, 오른쪽, 아래, 왼쪽
	int dirY[4] = { -1,0,1,0 };
	queue<VirusPos> q;

	q.push(virusPos[0]);

	while (!q.empty())
	{
		VirusPos vp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			
		}
	}
}
int solution(vector<vector<int>> labMap)
{
	vector<VirusPos> virusPos;

	for (int i = 0; i < labMap.size(); ++i)
	{
		for (int j = 0; j < labMap.size(); ++j)
		{
			if (labMap[i][j] == 2)
			{
				virusPos.push_back({ i,j,labMap[i][j] });
			}
		}
	}
}
int main()
{
	int n = 4, m = 6;
	int answer = 0;
	vector<vector<int>> labMap = {
		{0,0,0,0,0,0},
		{1,0,0,0,0,2},
		{1,1,1,0,0,2},
		{0,0,0,0,0,2}
	};

	/*cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int lab;
			cin >> lab;
			labMap[i].push_back(lab);
		}
	}*/

	answer = solution(labMap);
	cout << answer << endl;
}