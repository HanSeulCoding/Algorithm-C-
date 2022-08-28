#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
bool IsSquare(int row, int column, int indexSize, vector<int>&answer)
{
    int temp = map[row][column];
    if (indexSize != 1)
    {
        for (int i = row; i < row + indexSize; ++i)
        {
            for (int j = column; j < column + indexSize; ++j)
            {
                if (map[i][j] != temp)
                {
                    return false;
                }
            }
        }
    }
    if (temp == 0)
    {
        answer[0]++;
    }
    else if (temp == 1)
    {
        answer[1]++;
    }
    return true;
}
void CompressSquare(int row, int column, int indexSize, vector<int>&answer)
{

    if (IsSquare(row, column, indexSize, answer))
    {
        return;
    }

    CompressSquare( row, column, indexSize / 2, answer); //1사분면
    CompressSquare( row, column + indexSize / 2, indexSize / 2, answer); //2사분면
    CompressSquare( row + indexSize / 2, column, indexSize / 2, answer); //3사분면    
    CompressSquare( row + indexSize / 2, column + indexSize / 2, indexSize / 2, answer); //4사분면
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map = arr;

    CompressSquare(0, 0, arr.size(), answer);

    return answer;
}

int main()
{
    vector<vector<int>> arr = { {1,1,1,1,1,1,1,1}, {0,1,1,1,1,1,1,1}, {0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1} };

    vector<int> answer = solution(arr);
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}