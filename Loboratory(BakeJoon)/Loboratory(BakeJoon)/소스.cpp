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
//���� �¿�
int dirX[4] = { 0,0 ,-1,1 };
int dirY[4] = { -1,1,0,0 };
//2�� ���� ��Ű�� ���� ��,��,��,�쿡 1�� �־�� 1�� ���� ������
//0�� ī��Ʈ�� ���� �ȴ�.
//������ ������ 2�� ���� ��Ų��. �ٽ� 1�� ���ư���.
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
	//�� ��, ��,�� �� 1�� �־��.
	
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