#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> a[13];
int d[13];
void dijstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int current = pq.top().first;

		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;

		for (int i = 0; i < a[current].size(); ++i)
		{
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;

			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}
int solution(vector<int> music)
{
	int answer = 0;

	for (int i = 1; i <= 13; ++i)
	{
		d[i] = 100000;
	}
	a[1].push_back(make_pair(2, 1));
	a[1].push_back(make_pair(3, 1));
	a[2].push_back(make_pair(1, 1));
	a[2].push_back(make_pair(3, 1));
	a[3].push_back(make_pair(4, 1));
	a[3].push_back(make_pair(2, 1));
	a[3].push_back(make_pair(1, 1));
	a[3].push_back(make_pair(5, 1));

	a[4].push_back(make_pair(3, 1));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 1));
	a[5].push_back(make_pair(7, 1));

	a[6].push_back(make_pair(5, 1));
	a[6].push_back(make_pair(7, 1));

	a[7].push_back(make_pair(5, 1));
	a[7].push_back(make_pair(6, 1));
	a[7].push_back(make_pair(8, 1));

	a[8].push_back(make_pair(7, 1));
	a[8].push_back(make_pair(9, 1));
	a[8].push_back(make_pair(10, 1));

	a[9].push_back(make_pair(8, 1));
	a[9].push_back(make_pair(10, 1));
	a[10].push_back(make_pair(8, 1));
	a[10].push_back(make_pair(9, 1));
	a[10].push_back(make_pair(11, 1));
	a[10].push_back(make_pair(12, 1));
	a[11].push_back(make_pair(10, 1));
	a[11].push_back(make_pair(12, 1));
	a[12].push_back(make_pair(10, 1));
	a[12].push_back(make_pair(11, 1));

	for (int i = 0; i < music.size(); ++i)
	{
		if (i == 0)
		{
			dijstra(1);
			answer = d[music[0]];
			continue;
		}
		dijstra(music[i - 1]);
		answer += d[music[i]];
		for (int i = 1; i <= 13; ++i)
		{
			d[i] = 100000;
		}
	}
	return answer;
}

int main()
{
	vector<int> music = { 10,9,4,5,12 };
	int answer = solution(music);

	cout << answer << endl;
}