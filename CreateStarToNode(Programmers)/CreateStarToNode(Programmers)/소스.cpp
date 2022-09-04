#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Pos
{
    long long x = 0;
    long long y = 0;
    long long k = 0;
};
bool IsInterSection(Pos a, Pos b)
{
    if ((a.x * b.y) - (a.y * b.x) == 0)
    {
        return false;
    }
    return true;
}
Pos GetIntersection_Point(Pos a, Pos b)
{
    Pos point;
    long long adbc = (long long)((a.x * b.y) - (a.y * b.x));
    long long bfed = (long long)((a.y * b.k) - (a.k * b.y));
    long long ecaf = (long long)((a.k * b.x) - (a.x * b.k));

    if ((bfed % adbc != 0) || (ecaf % adbc != 0)) //정수만 출력하게
        return { 10000000001,10000000001,10000000001 };

    point.x = bfed / adbc;
    point.y = ecaf / adbc;

    return point;
}
vector<string> PrintScreen(vector<pair<int, int>> intersection_P, map<pair<int, int>, bool> temp)
{
    long long minY = 10000000001;
    long long maxY = -10000000001;
    long long minX = 10000000001;
    long long maxX = -10000000001;
    vector<string> printS;
    for (int i = 0; i < intersection_P.size(); ++i) //y값 가장 작은것을 고르자
    {
        minY = min((long long)intersection_P[i].second, minY);
        maxY = max((long long)intersection_P[i].second, maxY);
    }
    for (int i = 0; i < intersection_P.size(); ++i) //X값 가장 작은것을 고르자
    {
        minX = min((long long)intersection_P[i].first, minX);
        maxX = max((long long)intersection_P[i].first, maxX);
    }

    for (long long i = maxY; i >= minY; --i)
    {
        string s;
        for (long long j = minX; j <= maxX; ++j)
        {
            if (temp.count(make_pair(j, i)) != 0)
            {
                s += '*';
            }
            else
            {
                s += '.';
            }
        }
        printS.push_back(s);
    }
    return printS;
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<Pos> lineP;
    vector<pair<int, int>> intersection_P;
    map<pair<int, int>, bool> check;
    map<pair<int, int>, bool> temp;

    long long minY = 10000000001;
    long long maxY = -10000000001;
    long long minX = 10000000001;
    long long maxX = -10000000001;

    for (int i = 0; i < line.size(); ++i)
    {
        Pos p;

        p.x = line[i][0];
        p.y = line[i][1];
        p.k = line[i][2];
        lineP.push_back(p);
    }
    for (int i = 0; i < lineP.size(); ++i)
    {
        for (int j = 0; j < lineP.size(); ++j)
        {
            if (!IsInterSection(lineP[i], lineP[j])) // 교차 여부 판단
            {
                continue;
            }
            if (check[make_pair(i, j)]) //방문했던 두 선분 여부 판단.
            {
                continue;
            }
            check[make_pair(i, j)] = true;
            check[make_pair(j, i)] = true;
            Pos p = GetIntersection_Point(lineP[i], lineP[j]);
            if (p.x != 10000000001 && p.y != 10000000001 && p.k != 100000001)
            {
                intersection_P.push_back(make_pair(p.x, p.y));
                temp[make_pair(p.x, p.y)] = true;
            }
        }
    }
    answer = PrintScreen(intersection_P, temp);
    return answer;
}

int main()
{
    vector<vector<int>> line =
        { {2, -1, 4},{-2, -1, 4},{0, -1, 1}, {5, -8, -12}
        , {5, 8, 12} };
    /*{
        {0,1,-1},{1,0,-1},{1,0,1}
    };*/

    vector<string> answer = solution(line);
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}