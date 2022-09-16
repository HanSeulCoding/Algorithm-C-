#include <stdio.h>

#define INF 10000000

int a[6][6] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5 },
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};
int number = 6;
int v[6];
int d[6];
int GetSmallIndex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; ++i)
	{
		if (!v[i] && d[i] < min)
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}
void Dijstra(int start)
{
	for (int i = 0; i < number; ++i)
	{
		d[i] = a[start][i];
	}

	for (int i = 0; i < number - 1; ++i)
	{
		int current = GetSmallIndex();
		v[current] = true;                          
		for (int j = 0; j < number; ++j)
		{
			if (!v[j] && d[j] > a[current][j] + d[current])
			{
				d[j] = a[current][j] + d[current];
			}
		}
	}
}
int main()
{
	Dijstra(0);
	for (int i = 0; i < number; ++i)
	{
		printf("%d\n", d[i]);
	}
}