#include <iostream>
#include <vector>

using namespace std;
string board[50];
string WB[8] = {
       "WBWBWBWB",
       "BWBWBWBW",
       "WBWBWBWB",
       "BWBWBWBW",
       "WBWBWBWB",
       "BWBWBWBW",
       "WBWBWBWB",
       "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
int WB_Cnt(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[x + i][y + j] != WB[i][j])
                count++;
        }
    }
    return count;
}
int BW_Cnt(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[x + i][y + j] != BW[i][j])
            {
                count++;
            }
        }
    }
    return count;
}
int solution(int n, int m)
{
    int minNum = 12345;
    for (int i = 0; i +8  <= n; ++i)
    {
        for (int j = 0; j + 8 <= m; ++j)
        {
            int tmp;
            tmp = min(WB_Cnt(i, j), BW_Cnt(i, j));
            minNum = min(minNum, tmp);
        }
   }

   return minNum;
}

int main()
{
    int n = 10, m = 13;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    int answer = 0;
    answer = solution(n, m);
    cout << answer << endl;
}