#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    for (int i = 1; i < board.size(); ++i)
    {
        for (int j = 1; j < board[i].size(); ++j)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = min(min(board[i - 1][j - 1], board[i][j - 1]), board[i - 1][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}

int main()
{
    vector<vector<int>> board = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
    int answer = solution(board);

    cout << answer;
}