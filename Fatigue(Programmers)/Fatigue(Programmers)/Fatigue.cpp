#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> dungeon;
map<int, bool> check;
void Dfs(int index,int dungeonEnterCount, int k, int &answer)
{
    if (index == dungeon.size())
    {
        answer = max(dungeonEnterCount, answer);
        return;
    }
    for (int i = 0; i < dungeon.size(); ++i)
    {
        if (check[i])
            continue;

        bool isEnterDungeon = false;
        check[i] = true;
        if (k >= dungeon[i][0])
        {
            k -= dungeon[i][1];
            isEnterDungeon = true;
            dungeonEnterCount++;
        }

        Dfs(index + 1, dungeonEnterCount, k, answer);
        check[i] = false;
        if (isEnterDungeon)
        {
            k += dungeon[i][1];
            dungeonEnterCount--;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dungeon = dungeons;

    Dfs(0, 0, k, answer);
    return answer;
}

int main()
{
    int k = 80;
    vector<vector<int>> dungeons = { {100,20},{50,40},{30,10} };

    int answer = solution(80, dungeons);

    cout << answer << endl;
}