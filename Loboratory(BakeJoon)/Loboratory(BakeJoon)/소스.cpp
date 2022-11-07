#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> labMap;
struct Point
{
	int x = 0;
	int y = 0;
	int value = 0;
};
int wallCount = 0;
//상하 좌우
int dirX[4] = { 0,0 ,-1,1 };
int dirY[4] = { -1,1,0,0 };
//2를 증식 시키기 전에 상,하,좌,우에 1을 넣어보고 1에 전부 막히면
//0의 카운트를 세면 된다.
//막히지 않으면 2를 증식 시킨다. 다시 1로 돌아간다.
void Dfs(Point virus, vector<Point> virusVector)
{
	if (virus.x < 0 || virus.x > labMap[0].size() - 1
		|| virus.y < 0 || virus.y > labMap.size() - 1)
		return;

	//virus
	for (int i = 0; i < virusVector.size(); ++i)
	{
		Point currentPos = virus;
		for (int j = 0; j < 4; ++j)
		{
			Dfs({ currentPos.x + dirX[j], currentPos.y + dirY[j] }, virusVector);
		}
		
	}
	//상 하, 좌,우 에 1을 넣어보자.
	
}
int solution()
{
	vector<Point> virus;
	for (int i = 0; i < labMap.size(); ++i)
	{
		for (int j = 0; j < labMap.size(); ++j)
		{
			if (labMap[i][j] == 2)
			{
				virus.push_back({ i,j,2 });
			}
		}
	}
}

int main()
{
	int n, m;
	int answer = 0;
	//cin >> n >> m;
	 labMap = {
		{2,0,0,0,1,1,0},
		{0,0,1,0,1,2,0},
		{0,1,1,0,1,0,0},
		{0,1,0, 0, 0,0,0},
		{0,0,0,0,0,1,1},
		{0,1,0, 0,0,0,0},
		{0,1,0,0,0,0,0}
	};

	answer = solution();
	cout << answer << endl;
	
}