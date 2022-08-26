#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    map<pair<pair<int, int>, pair<int, int>>, bool> graph;
    int prevRow = 5;
    int prevColumn = 5;
    for (int i = 0; i < dirs.size(); ++i)
    {
        int column = prevColumn;
        int row = prevRow;

        if (dirs[i] == 'U')
        {
            if (row + 1 > 10)
            {
                continue;
            }
            row = row + 1;
        }
        if (dirs[i] == 'D')
        {
            if (row - 1 < 0)
            {
                continue;
            }
            row = row - 1;
        }
        if (dirs[i] == 'R')
        {
            if (column + 1 > 10)
            {
                continue;
            }
            column = column + 1;
        }
        if (dirs[i] == 'L')
        {
            if (column - 1 < 0)
                continue;
            column = column - 1;

        }

        if (graph[make_pair(make_pair(row, column), make_pair(prevRow, prevColumn))])
        {
            prevRow = row;
            prevColumn = column;
            continue;
        }

        graph[make_pair(make_pair(row, column), make_pair(prevRow, prevColumn))] = true;
        graph[make_pair(make_pair(prevRow, prevColumn), make_pair(row, column))] = true;
        answer++;
        prevRow = row;
        prevColumn = column;
    }
    return answer;
}


int main()
{
    string s = "ULURRDLLU";
    int answer = solution(s);

    cout<<answer<<endl;
}